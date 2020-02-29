#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;


// 1-2 =>  2, 3
// 2-3 => 1, 3
// 2-4 => 4.


int main(){
    vector<int> from{1,1,2,2,2};
    vector<int> to{2,2,3,3,4};
   vector<int> weight{2,3,1,3,4};
    map<int , set<int>> myMap;

    int n = weight.size();
    for(int i = 0 ; i<n ; i++){
        myMap[weight[i]].insert(from[i]);
        myMap[weight[i]].insert(to[i]);
    }

    cout<<endl;
    int m = 0;
    int start = 0;
    for( auto itr : myMap)
    {
        if( m < itr.second.size()){
            m = itr.second.size();
            start = itr.first;
        }
    }
    set<int> s = myMap[start];
    for( auto itr : s){
        cout<<itr<<" ";
    }
    return 0;
}

