#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = { 2,4,6,8};
    int len = arr.size();
    int sum = 8;

    vector<vector<int>> dp(sum+1 , vector<int>(len+1));

    for(int i = 0 ; i <= len ;i++){
        dp[0][i] = 1;
    }

    for(int i = 1 ; i <= sum ; i++) {
        dp[i][0] = 0;
    }

    for(int i = 1 ; i <= sum ; i++) {
        for(int j = 1 ; j <= len ; j++) {
            if( arr[j-1] <= i) {
                dp[i][j] = dp[i - arr[j-1]][j] + dp[i][j-1];
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
       // cout<<endl;
    }

    for(int i =0 ; i <= sum ; i++){
        for(int j = 0 ; j<= len ; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

