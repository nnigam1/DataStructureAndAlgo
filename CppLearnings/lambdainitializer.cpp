#include<iostream>
using namespace std;

int main()
{
    auto x = 1;
    auto task = [&r = x , x = x+10] () {
        ++r;
        return r + x;
    };

   cout<< task()<<" ";
   cout<<x<<" ";
   return 0;
}

