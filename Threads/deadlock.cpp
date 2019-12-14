#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

class LogFile {
    mutex mu;
    mutex mu2;
    // resource you want to lock
public:
    void shared_print()
    {
        lock_guard<mutex> locker(mu);
        for(int i = 0 ; i < 50 ; i+=2) {
            cout << "Hello i am from shared print 1 : " << i << endl;
            this_thread::sleep_for(chrono::milliseconds(1));
        }
    }

    void shared_print2()
    {
        lock_guard<mutex> locker(mu);
        for(int i = 1 ; i < 50 ; i+=2) {
            cout << "Hello i am from shared print 2 :" << i << endl;
        }
    }

    void shared_print3()
    {
        unique_lock<mutex> lock(mu , std::defer_lock);
        cout<<"hello"<<endl;
        mu.lock();
        cout<<"locked"<<endl;
        mu.unlock();
    }
};

void function1(LogFile& log)
{
    log.shared_print3();
}

int main()
{
    LogFile log;
    thread t1(function1 , std::ref(log));

    log.shared_print3();

    if(t1.joinable())
        t1.join();
    return 0;
}

