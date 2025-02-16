#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex forks[5]; // 5 chopsticks (one for each philosopher)

void philosopher(int id)
{
    int left = id;            // Left fork index
    int right = (id + 1) % 5; // Right fork index

    while (true)
    {
        cout << "Philosopher " << id << " is thinking.\n";
        this_thread::sleep_for(chrono::milliseconds(1000));

        // Even-indexed philosophers pick left first, then right
        if (id % 2 == 0)
        {
            forks[left].lock();
            forks[right].lock();
        }
        // Odd-indexed philosophers pick right first, then left
        else
        {
            forks[right].lock();
            forks[left].lock();
        }

        // Eating
        cout << "Philosopher " << id << " is eating.\n";
        this_thread::sleep_for(chrono::milliseconds(1000));

        // Release forks
        forks[left].unlock();
        forks[right].unlock();
    }
}

int main()
{
    thread philosophers[5];

    for (int i = 0; i < 5; i++)
    {
        philosophers[i] = thread(philosopher, i);
    }

    for (int i = 0; i < 5; i++)
    {
        philosophers[i].join();
    }

    return 0;
}
