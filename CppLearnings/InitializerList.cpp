#include<iostream>
#include<vector>
using namespace std;

int Sum(const std::initializer_list<int>& list)
{
    int sum = 0 ;
    for( auto itr : list)
    {
        sum+=itr;
    }
    return sum;
}

int main()
{
    cout<<Sum({1,2,3,4,5});
    vector<int> b = {1,2,3,4,5};

    return 0;
}

