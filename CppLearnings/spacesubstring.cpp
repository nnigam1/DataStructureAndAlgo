#include<iostream>
#include<string>
#include<set>
using namespace std;

void putSpace(string str ,int index ,int len , set<string>& s , string temp) {

    if( index == len){
        s.insert(temp);
        return;
    }

    temp+=str[index];
    if( index+1 < len) {
        putSpace(str, index + 1, len, s, temp + ' ');
        putSpace(str, index + 1, len, s, temp);
    } else
        putSpace(str , index+1, len , s, temp);
}

int main(){
    string str = "ABCD";
    int len = str.size();
    string temp  = "";
    set<string> s;
    putSpace(str , 0 , len , s , temp);
    for( auto itr : s){
        cout<<itr<<endl;
    }
    cout<<s.size()<<endl;
    return 0;
}

