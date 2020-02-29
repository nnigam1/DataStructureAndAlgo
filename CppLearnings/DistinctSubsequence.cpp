#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string S = "babgbag";
    string T = "bag";
    int n = S.length();
    int m = T.length();

    int table[n+1][m+1];

    for(int i = 0 ; i<= n ; i++){
        for(int j = 0 ; j<=m ; j++) {
            table[i][j] = 0;
        }
    }

    for(int i = 0 ; i <=m ; i++){
        table[i][0] = 1;
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=m ;j++){
            if( S[i-1] == T[j-1]){
                table[i][j] = table[i-1][j-1] + table[i-1][j];
            } else {
                table[i][j] = table[i-1][j];
            }
        }
    }

    for(int i = 0 ; i<= n ; i++){
        for(int j = 0 ; j<=m ; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
