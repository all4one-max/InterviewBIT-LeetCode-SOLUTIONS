import asyncio


class AsyncRWLock:
    """
    A write preference reader-writer lock
    1. Will not allow any read operation until tasks are waiting for write operations
    2. Will ensure that only 1 task performs write operation at a time
    3. Will ensure no task goes to read operation by making them wait on write event which will be
    set to false until writers are waiting
    """

    def __init__(self) -> None:
        self._write_lock_counter = asyncio.Lock()
        self._read_lock_counter = asyncio.Lock()
        self._write_lock = asyncio.Lock()
        self._writers = 0
        self._readers = 0
        self._writer_waiting = asyncio.Event()
        self._writer_waiting.set()

    async def acquire_read(self) -> None:
        await self._writer_waiting.wait()  # wait until no writer is waiting
        async with self._read_lock_counter:
            self._readers += 1
            if self._readers == 1:
                await self._write_lock.acquire()

    async def release_read(self) -> None:
        async with self._read_lock_counter:
            self._readers -= 1
            if self._readers == 0:
                self._write_lock.release()  # release write lock

    async def acquire_write(self) -> None:
        await self._write_lock_counter.acquire()
        self._writers += 1
        self._write_lock_counter.release()
        if self._writers == 1:
            self._writer_waiting.clear()  # block all readers
        await self._write_lock.acquire()

    async def release_write(self) -> None:
        await self._write_lock_counter.acquire()
        self._writers -= 1
        self._write_lock_counter.release()
        self._write_lock.release()
        if self._writers == 0:
            self._writer_waiting.set()  # allow readers to read
