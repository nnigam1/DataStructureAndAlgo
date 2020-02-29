#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> freq;
        for( auto itr : words)
        {
            freq[itr]++;
        }
        auto myLambda = [](pair<int, string> a , pair<int , string> b){
            if( a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue <pair<int, string>, vector<pair<int, string>>, decltype(myLambda) > pq(myLambda);
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

        vector<string> vec(k);
        for(int j = 0 ; j <k ; j++)
        {
            vec[j] = pq.top().second;
            pq.pop();
        }
        reverse(vec.begin() , vec.end());
        return vec;
    }
};
