#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;


int main() {
    string str = "Hello!!!, he said ---and went....";
                //012345678
    int len = str.length();
    for(int i = 0 ; i < str.length() ; i++) {
        if( ispunct(str[i])) {
            str.erase(i, 1);
            cout<<i<<" "<<str<<endl;
            i--;
        }
    }

    cout<<str<<endl;
    return 0;
}

