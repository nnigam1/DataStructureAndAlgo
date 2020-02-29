#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int count = 0;
    string str = "ybghjhbuytb";
    sort(str.begin() , str.end());
    do{
       count++;
    } while(next_permutation(str.begin() , str.end()));
    cout<<count;
    return 0;
}