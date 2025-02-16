#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

const int N = 100; // Number of iterations
bool flag[2] = {false, false};
int turn = 0;
int shared_data = 0;

void process(int id)
{
    int other = 1 - id;
    for (int i = 0; i < N; i++)
    {
        // Entry section
        flag[id] = true;
        turn = other;

        while (flag[other] && turn == other)
        {
            // Busy wait
        }

        // Critical Section
        shared_data++;

        // Exit section
        flag[id] = false;
    }
}

int main()
{
    thread t1(process, 0);
    thread t2(process, 1);

    t1.join();
    t2.join();

    cout << "Final shared data: " << shared_data << endl; // Should be 2 * N
    return 0;
}
