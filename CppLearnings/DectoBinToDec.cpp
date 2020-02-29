#include<iostream>
#include<math.h>
using namespace std;
#define M 32
int main(){
    int num = 80;

    string str = "";
    int index = 0;
    while( num > 1){
        str += ( num% 2) ? "1" :"0";
        num = num/2;
    }
    if( num == 1) {
        str += "1";
    }
    else if( num == 0)
        str+="0";
    reverse(str.begin() , str.end());
    cout<<str<<endl;
    // binary to dec again
    int len = str.length();
    int res = 0;
    int base = 1;
    for(int i = len -1; i>=0 ; i--){
        if( str[i] == '1'){
            res+=base;
        }
        base = base * 2;
    }
    cout<<res<<endl;
    int n = 111;
    cout<<to_string(n);
    return 0;
}
