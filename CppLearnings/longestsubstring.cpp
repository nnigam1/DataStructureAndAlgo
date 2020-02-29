class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        int count = 0;
        unordered_set<char , int> ums;
        for(int i = 0 ; i < n ; i++) {
            if(ums.find(s[i]) != ums.end()) {
                maxi = max(maxi , ums.size());
                i = ums.find(s[i]);
                ums.clear();
                ums.insert({s[i] , i});
            }
        }
        return max(maxi , count);
    }
};

