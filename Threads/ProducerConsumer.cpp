// we are going to create producer-consumer problem.
// where producer will write data in deque and consumer will consume.
// but consumer can consume in two ways :
// via push or pull , if it will do via pull quite inefficient here as consumer has to keep
// checking whether there is some data in deque or not.
// but push model is better where producer will tell consumer that ok i have data get notified
// this can be possible through condition variables.

#include<iostream>
#include<mutex>
#include<thread>
#include<queue>
using namespace std;

deque<int> q;
mutex mu;
condition_variable cond;

void producer() {
    int count = 10;
    while(count > 0 )
    {
        unique_lock<mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        cond.notify_one();
        this_thread::sleep_for(chrono::milliseconds(100));
        count--;
    }
}

// this is pull model of consumer , which is very inefficient as client every time have to
// lock unlock the resource and check whether data is available or not.
void inEfficientConsumer() {
    int data = 0 ;
    while( data != 1) {
        unique_lock<mutex> locker(mu);
        if( !q.empty()) {
            data = q.back();
            cout << data << endl;
            q.pop_back();
        }
        locker.unlock();
    }
}

// this is push model of consumer , which is efficient , here consumer will call cond.wait and wait
// or sleep until he gets the notify which is nothing but wake up in the same condition variable.
// why consumer need to pass its locker object in the cond.wait(locker) ??? so consumer is going on sleep
// for indefinite amount of time until he gets notified so this locker object will be unlocked by OS.
// and will be given back as soon as consumer gets notify call over same cond variable.
void noSelfWakeUpConsumer() {
    int data = 0 ;
    while( data != 1) {
        unique_lock<mutex> locker(mu);
        cond.wait(locker); //now no need of empty check as consumer will only be wake up after data available.
        data = q.back();
        q.pop_back();
        locker.unlock();
        cout << data << endl;
    }
}

// now so far everything is good , but consumer can back in between without notify also
// so we need something so that it will check whether data is available and if yes ,
// then consumer will be wake up else sleep again. cond variable will take pred also.
void consumer() {
    int data = 0 ;
    while( data != 1) {
        unique_lock<mutex> locker(mu);
        cond.wait(locker , []() {
            return !q.empty();
        }); // need of empty check as consumer can wake up in between also, so for that this check is needed.
        data = q.back();
        q.pop_back();
        locker.unlock();
        cout << "Consumer gets the data : "<< data << endl;
    }
}

int main()
{
    thread prod(producer);
    thread cons(consumer);

    prod.join();
    cons.join();
    return 0;
}





