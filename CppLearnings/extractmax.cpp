#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string str = "abchsd0365sdhs";
    int len = str.length();
    string temp = "";
    int ans = 0;
    for(int i = 0 ; i < len ; i++) {
        if( isdigit(str[i])){
            temp += str[i];
        }
        else {
            ans = max(ans , atoi(temp.c_str()));
            temp = "";
        }
    }
    cout<<ans;
    return 0;
}


