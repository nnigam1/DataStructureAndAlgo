#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    string str = "ababbbabbababa";
    int len = str.length();
    vector<vector<bool>> dp(len , vector<bool>(len));

    for(int i = 0 ; i <len ; i++)
        dp[i][i] = true;

    for(int L = 2 ; L <= len ; L++) {
        for(int i = 0 ; i < len-L+1 ; i++) {
            int j = i+L-1;
            if(L==2) {
                dp[i][j] = (str[i] == str[j])? true : false;
            } else {
                dp[i][j] = (str[i] == str[j]) && dp[i+1][j-1];
            }
        }
    }

    for(int i = 0 ; i< len ; i++) {
        for(int j = 0 ; j <len ; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}
