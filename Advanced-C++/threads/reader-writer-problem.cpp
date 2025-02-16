#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

// Shared resource
int shared_data = 0;

// Synchronization primitives
mutex m_rw;             // Mutex for writer (exclusive access)
mutex read_count_mutex; // Protects access to read_count
int read_count = 0;     // Number of active readers

void reader(int id)
{
    while (true)
    {
        read_count_mutex.lock(); // Protect access to read_count
        read_count++;
        if (read_count == 1)
        { // First reader locks the writer
            m_rw.lock();
        }
        read_count_mutex.unlock();

        // Reading (simultaneous)
        cout << "Reader " << id << " is reading: " << shared_data << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));

        read_count_mutex.lock();
        read_count--;
        if (read_count == 0)
        { // Last reader unlocks the writer
            m_rw.unlock();
        }
        read_count_mutex.unlock();

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void writer(int id)
{
    while (true)
    {
        m_rw.lock(); // Writers need exclusive access

        // Writing
        shared_data++;
        cout << "Writer " << id << " is writing: " << shared_data << endl;
        this_thread::sleep_for(chrono::milliseconds(1500));

        m_rw.unlock();

        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    thread readers[3], writers[2];

    for (int i = 0; i < 3; i++)
    {
        readers[i] = thread(reader, i + 1);
    }

    for (int i = 0; i < 2; i++)
    {
        writers[i] = thread(writer, i + 1);
    }

    for (int i = 0; i < 3; i++)
    {
        readers[i].join();
    }

    for (int i = 0; i < 2; i++)
    {
        writers[i].join();
    }

    return 0;
}
