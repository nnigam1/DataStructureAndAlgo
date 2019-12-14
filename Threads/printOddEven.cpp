#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

mutex mu;

void shared_print(string msg , int i)
{
    lock_guard<mutex> guard(mu);
    cout<< msg << i<< endl; // this is not good mutex and resource should be in same file , and tightly coupled ,
    // no one use resource without mutex.

}

void threadPrint()
{
    for(int i = 1 ; i <= 50 ;  i+=2) {
        shared_print("From Thread t1 : " , i);
        this_thread::sleep_for(chrono::milliseconds(2));
    }
}

int main()
{
    thread t1(threadPrint);

    for(int i = 0 ; i <= 50 ; i+=2)
    {
        shared_print("From Thread main : " , i);
        this_thread::sleep_for(chrono::milliseconds(2));
    }
    if(t1.joinable())
        t1.join();

    return 0;
}

