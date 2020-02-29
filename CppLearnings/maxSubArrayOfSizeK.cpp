#include<iostream>
#include<queue>
using namespace std;

int main()
{
    vector<int> ve = {1,9,-1,-2,7 , 3 , -1, 2};
    int n = ve.size();
    int k = 4;
    int wSum = 0 ;
    int mSum = 0;
    int start = 0;
    int i = 0;

    for( ; i < k ; i++) {
        wSum += ve[i];
    }
    if( mSum < wSum)
        mSum = wSum;

    for( ; i < n ; i++) {
        wSum -= ve[start];
        start++;
        wSum += ve[i];
        if(wSum > mSum)
            mSum = wSum;
    }
    cout<<mSum<<" "<<endl;
    return 0;
}

