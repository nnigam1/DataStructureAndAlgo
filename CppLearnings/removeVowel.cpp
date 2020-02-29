#include<iostream>
#include<string>
using namespace std;

bool isVow(char c) {
    if( c == 'a' || c == 'i' || c == 'e'||
        c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

int main() {
    string str = "geeks for geeaieousks";
    int len = str.length();
    bool lastVow = false;
    for(int i = 0 ; i < len ; i++){
        if(isVow(str[i])) {
            if( lastVow == true){
                str.erase(i,1);
                i--;
            }
            else {
                lastVow = true;
            }
        } else {
            lastVow = false;
        }
    }
    cout<<str;
    return 0;
}

