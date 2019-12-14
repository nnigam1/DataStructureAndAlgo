#include<iostream>
using namespace std;

constexpr int getData(int x )
{
    if( x == 0)
        return 1;
    return x + getData(x -1);
}


constexpr int  getDataEffective(int x , int sum )
{
    if( x == 0) {
       return sum;
    }
    return getDataEffective(x -1 , sum+x);
}

int main()
{
    int x = 4;
    int sum = 1;
   // cout<<getData(x)<<endl;
   cout<<getDataEffective(x, sum);

    return 0;
}

