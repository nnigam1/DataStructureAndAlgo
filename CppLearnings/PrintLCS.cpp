#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lcs[100][100];

void recursiveLca(string x , string y , int m , int n , vector<char>& ch , int index){
    if( m == 0 || n == 0) {
        for(char c : ch){
            cout<<c;
        }
        cout<<endl;
        return;
    }

    if( x[m-1] == y[n-1]) {
        ch[index] = x[m-1];
        index = index+1;
        recursiveLca(x , y , m-1 , n-1 ,ch, index);
    }

    if( lcs[m][n-1] > lcs[m-1][n]) {
        recursiveLca( x , y , m , n-1 , ch , index+1 );
    }
    else {
        recursiveLca(x , y , m-1 , n , ch , index+1);
    }
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";
    string str = "";

    int m = X.length();
    int n = Y.length();

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
                str += "";
            } else {
                if (X[i - 1] == Y[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
    }
vector<char> v(4);
 recursiveLca(X , Y , m ,n , v , 0);
    cout << lcs[m][n] << endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++) {
            cout<<lcs[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



