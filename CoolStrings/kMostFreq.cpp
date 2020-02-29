#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for( auto itr : nums)
        {
            freq[itr]++;
        }
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        for( auto itr : freq)
        {
            if( i < k)
            {
                pq.push({make_pair(itr.second , itr.first)});
                i++;
            }
            else
            {
                if( itr.second > pq.top().first)
                {
                    pq.pop();
                    pq.push({make_pair(itr.second , itr.first)});
                }
            }
        }

        vector<int> vec(k);
        for(int j = 0 ; j <k ; j++)
        {
            vec[j] = pq.top().second;
            pq.pop();
        }
        reverse(vec.begin() , vec.end());
        return vec;
    }
};

//input :
//[1,1,1,2,2,3]
//2

