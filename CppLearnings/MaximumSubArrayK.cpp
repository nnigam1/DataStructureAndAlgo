#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    vector<int> vec = {1,2,3,1,4,5,2,3,6};
    int n = vec.size();
    int k = 3;
    int max = 0;

    for(int i = 0 ; i <= n - k ; i++) {
        max = vec[i];
        for( int j = i ; j < i+k ; j++) {
            if( vec[j] > max)
                max = vec[j];
        }
        cout<<max<<" ";
    }
    cout<<endl;
    int j = 0;
    priority_queue<int> pq;
    for( ; j < k ; j++) {
        pq.push(vec[j]);
    }

    while( j <= n) {
        int top = pq.top();
        cout<<top<<" ";
       // cout<<"element "<<vec[i]<<" "<<endl;
        pq.push(vec[j]);
        j++;
    }
    int i = 0;
    int m = 0;
    deque<int> dq(3);
    for( ; i < k ; i++) {
        dq.push_back(vec[i]);
        if( m < vec[i])
            m = vec[i];
    }
    cout<<m<<" ";
    while(i < n )
    {
        int top = dq.front();
        dq.pop_front();
        dq.push_back(vec[i]);
        if( top != m ) {
            vector<int
        }
        i++;
    }

}
