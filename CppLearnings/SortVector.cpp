#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> vec = {3,8,1,4,0,99};
    sort(vec.begin() , vec.end() , [](const int i , const int j) {
        return i > j;
    });

    int sum = 0;
    for_each(vec.begin() , vec.end() , [vec , &sum] (const int &i) {
        cout<<vec[i]<<" ";
    });



    return 0;
}

