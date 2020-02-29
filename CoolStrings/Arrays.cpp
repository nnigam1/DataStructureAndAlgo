#include<iostream>
#include<vector>
using namespace std;

bool reverse(vector<int> &v , int l , int r )
{
    while(l<=r)
    {
        int temp = v[l];
        v[l] = v[r];
        v[r] = temp;
        l++;
        r--;
    }
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int k = 4;
    int n = vec.size();
    int i = 0;
    while(i<n)
    {
        int l = i + k;
        int r = i + 2*k - 1;
        if( l < n && l < r)
        {
            if(r < n)
                reverse(vec , l , r);
            else {
                reverse(vec, l, n-1);
            }
        }
        i = r + 1;
    }

    for(auto itr : vec)
        cout<<itr<<" ";
return 0;
}



