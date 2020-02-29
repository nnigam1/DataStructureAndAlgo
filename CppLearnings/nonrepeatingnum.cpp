#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec = {2, 3, 8, 16, 11, 2, 3, 11};
    int n = vec.size();
    int Xor;
    for( auto itr : vec){
        Xor ^= itr;
    }

    int setBit = Xor & -(Xor);

    int x, y = 0;

    for(int i = 0 ; i< n ; i++) {
        if( vec[i] & setBit)
            x ^= vec[i];
        else {
            y ^= vec[i];
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}

