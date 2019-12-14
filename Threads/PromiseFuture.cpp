#include<iostream>
#include<future>
using namespace std;

int factorial(future<int>& fu)
{
    cout<<"child says - 'i will wait until parent thread resolve it's promise'"<<endl;
    int n = fu.get();
    int res = 1;
    for(int i = 1 ; i<= n ; i++)
        res = res * i;
    this_thread::sleep_for(chrono::milliseconds(10000));
    return res;
}

//int main_old()
//{
//    // let's get the value back from the child thread using future
//    future<int> fu = async(launch::async , factorial , 4);
//    cout<<"hello hello i am going to wait until you give the data"<<endl;
//    int res = fu.get();
//    cout<<res<<endl;
//    return 0;
//}

int main()
{
    // let's send the value also to child thread using promise and future.
    promise<int> prom;
    future<int> fu2 = prom.get_future();
    future<int> fu = async(launch::async , factorial , std::ref(fu2));
    this_thread::sleep_for(chrono::milliseconds(10000));
    cout<<"parent says : 'ohh ! i have a promise to fulfil with my child , Let me do that' "<<endl;
    prom.set_value(4);
    cout<<"parent continue : 'hello hello i am going to wait until you give the data' "<<endl;
    int res = fu.get();
    cout<<res<<endl;
    return 0;
}
