#include<iostream>
#include<thread>
using namespace std;

auto myLambda = ([](string& s) {
    cout<<s<<endl;
    s+=" Neha";
});

int main()
{
    string str = "hello my name is:";
    cout<<this_thread::get_id()<<endl;
    thread t1(myLambda , std::ref(str));
    cout<<t1.get_id()<<endl;
    cout<<t1.hardware_concurrency()<<endl;

    if( t1.joinable())
        t1.join();

    cout<<str<<endl;
    return 0;
}
