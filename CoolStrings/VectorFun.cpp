#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v(1);
    v[0] = 1;
    v.push_back(2);
    cout<<v.front()<<endl;
    v.push_back(3);
    v.push_back(4);
    cout<<v[3]<<endl;
    for( auto itr : v)
        cout<<itr<<" ";
    cout<<endl;
    return 0;
}


