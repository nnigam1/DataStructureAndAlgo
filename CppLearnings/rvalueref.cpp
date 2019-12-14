#include<iostream>
#include<vector>
using namespace std;


int f()
{
    vector<int> vec;
    vec.push_back(1);
    cout<<vec[0];
    for( auto itr : vec)
    {
        cout<<itr;
    }
}

int main()
{
    f();
    return 0;
}

