#include<iostream>
#include<functional>
using namespace std;

auto myLambda = [](int a , int b ) -> int{
    return a + b;
};

int getAdd(std::function<int(int,int)> func)
{
    return func( 23, 78);
}

int main()
{
    int y = getAdd(myLambda);
    cout<<y<<endl;
    return 0;
}

