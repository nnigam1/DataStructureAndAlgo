#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
#define sumi 12
#define ni 500

vector<vector<int>>dp (sumi , vector<int>(ni , -1));

unsigned long long countRec(int sum , int n){
    if( n == 0 ) {
        if( sum == 0) {
            cout << "i am done" << endl;
            return 1;
        }
        return 0;
    }

    if( dp[sum][n] != -1)
        return dp[sum][n];

    unsigned long long res = 0;
    for(int i = 1; i <= 9 ; i++){
        if( sum -i>= 0){
           res+=countRec(sum - i , n-1);

        }
    }
    return dp[sum][n] = res;
}

int main(){
    int n = 12;
    int sum = 500;

    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    unsigned long long ans = countRec(sum  , n);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    auto timeElapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout<<"Elapsed time : "<< timeElapsed;
    return 0;
}