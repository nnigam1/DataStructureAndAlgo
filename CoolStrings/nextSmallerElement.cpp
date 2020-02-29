#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    //vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> arr = { 1, 2, 3};
    int n = arr.size();
    vector<int> ans(n , -1);

    stack<int> s;
    s.push(arr[0]);
    for( int i = 1 ; i< n ; i++ )
    {
        if(arr[i] > s.top())
            ans[i] = s.top();
        else
            s.push(arr[i]);
    }
    for( auto itr : ans)
    {
        cout<<itr<<" ";
    }
    return 0;
}

