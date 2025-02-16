#include <iostream>
#include <thread>
#include <semaphore>
#include <bits/stdc++.h>
using namespace std;

counting_semaphore<2> sem(2); // Max 2 threads can access the resource

void access_resource(int id)
{
    sem.acquire(); // Decrement semaphore
    cout << "Thread " << id << " is accessing the resource.\n";
    this_thread::sleep_for(chrono::seconds(1));
    sem.release(); // Increment semaphore
}

int main()
{
    thread t1(access_resource, 1);
    thread t2(access_resource, 2);
    thread t3(access_resource, 3); // This will wait until another thread releases

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
