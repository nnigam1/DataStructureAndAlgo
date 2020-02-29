#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;

int main() {
    string str = "aaabc";
    string str2 = "";
    using pic = pair<int , char>;
    map<char , int> count;
    int len = str.length();
    for(int i = 0 ; i< len ; i++)
    {
        count[str[i]]++;
    }
    auto myLambda = [](pic a , pic b) -> bool{
        if( a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    };
    priority_queue<pic , vector<pic> , decltype(myLambda)> pq(myLambda);
    for(auto itr : count) {
        pq.push({itr.second , itr.first});
    }
    int index = 0;
    pic prevval;
    while( !pq.empty()) {
        pic temp = pq.top();
        pq.pop();
        temp.first--;
        str[index] = temp.second;
        if(prevval.first != 0) {
            pq.push(prevval);
        }
        index++;
        prevval = temp;
    }

    if( pq.empty() && prevval.first != 0){
        cout<<"Not possible"<<endl;
    } else{
        cout<<str<<endl;
    }
    return 0;
}