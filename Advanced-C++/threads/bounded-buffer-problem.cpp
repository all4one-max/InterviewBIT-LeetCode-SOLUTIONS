#include <iostream>
#include <queue>
#include <thread>
#include <semaphore>
#include <chrono>

std::queue<int> buffer;
const int max_size = 5;
std::mutex mtx;

std::counting_semaphore<max_size> empty_slots(max_size); // Track empty slots
std::counting_semaphore<0> full_slots(0);                // Track filled slots

void producer(int id)
{
    int item = 1;
    while (true)
    {
        empty_slots.acquire(); // Wait for empty slot
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(item);
            std::cout << "Producer " << id << " produced: " << item << "\n";
            item++;
        }
        full_slots.release(); // Signal item available
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void consumer(int id)
{
    while (true)
    {
        full_slots.acquire(); // Wait for an available item
        int item;
        {
            std::lock_guard<std::mutex> lock(mtx);
            item = buffer.front();
            buffer.pop();
            std::cout << "Consumer " << id << " consumed: " << item << "\n";
        }
        empty_slots.release(); // Signal empty space available
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    std::thread producers[2], consumers[2];

    for (int i = 0; i < 2; i++)
        producers[i] = std::thread(producer, i + 1);

    for (int i = 0; i < 2; i++)
        consumers[i] = std::thread(consumer, i + 1);

    for (auto &t : producers)
        t.join();
    for (auto &t : consumers)
        t.join();

    return 0;
}
