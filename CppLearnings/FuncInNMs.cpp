#include<iostream>
#include<thread>
#include<chrono>
#include<functional>
using namespace std;

void timer_start(std::function<void(void)> func, unsigned int interval) {
    thread([func , interval](){
        while(true){
            auto x = chrono::steady_clock::now() + chrono::milliseconds(interval);
            func();
            this_thread::sleep_until(x);
        }
    }).detach();
}

void someFunc(){
    cout<<"Hello i am some function"<<endl;
}

int main() {
    timer_start(someFunc , 1000);
    this_thread::sleep_for(chrono::seconds(10));
    return 0;
}

