#include<iostream>
#include<memory>
#include<future>
using namespace std;

// if we want to pass something to thread but we don't have value present , so we
// promise to thread that will give value. and pass the promises's future.
// fir getting the value from thread also we will receive the future from thread and call get over it
// to get the value from thread.

int factorial(future<int>& f){
    int res = 1;
    int N = f.get();
    for(int i = N ; i > 0 ; i--){
        res*= i;
    }
    return res;
}

int main(){
    promise<int> p;
    future<int> f = p.get_future();
    future<int> fu = async(launch::async , factorial , ref(f));
    this_thread::sleep_for(chrono::milliseconds(10));
    p.set_value(4);
    int res = fu.get();
    cout<<"Value is : "<<res<<endl;
    return 0;
}

// Now if we have to call factorial function many times, each time we can't just pass
// same future , because we can't call f.get() every time in the same future .
// so lib provides a way to do so shared_future by using this we can pass by value
// shared_future<int> sf = f.share().
// and then pass sf in async.
// so take future from promise and shared_future from future.share.