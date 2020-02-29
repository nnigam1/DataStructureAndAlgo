#include<iostream>
using namespace std;

int main(){
    int n = 9 , k = 3;
    int nCk = 1; // nC0 = 1;
    if( k > n-k){
        // to run the loop for shorter value.
        k = n-k ;
    }
    // Finding nCk from nC(k-1)
    for(int i = 1; i <=k ; i++ ){
        nCk *= ( n - i + 1);
        nCk /= i;
    }
    cout<<nCk<<endl;
    return 0;
}
