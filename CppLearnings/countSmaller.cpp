#include<iostream>
#include<set>
#include<vector>
using namespace std;


vector<int> countSmaller(vector<int>& nums) {
    using iPair = pair<int , int>;
    int n = nums.size();
    set<iPair> s;
    vector<int> result(n);
    for(int i = 0 ; i < n ; i++ ) {
        s.insert({nums[i] , i});
    }
    for(int i = 0 ; i < n ; i++)
    {
        int count = 0;
        auto itr = s.find({nums[i] , i});
        for( auto in = s.begin() ; in != itr ; in++ ) {
            if( in->second > itr->second)
                count++;
        }
        result[itr->second] = count;
    }
    return result;
}

int main() {
    vector<int> nums = {5,2,6,1};
    vector<int> result = countSmaller(nums);
    for( auto itr : result) {
        cout<<itr<<endl;
    }
    return 0;
}