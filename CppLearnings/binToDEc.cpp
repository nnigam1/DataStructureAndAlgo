#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;
    int x = 44; // 100011
    while(x!=0){
        vec.push_back(x&1);
        x = x>>1;
    }
    vec.push_back(0);
    int last_find = 0;
    int n = vec.size();
    for(int i = 1 ; i< n-1 ; i++){
        if( vec[i] == 1 && vec[i-1] == 1 && vec[i+1] == 0) {
            vec[i+1] = 1;
            for(int j = i ; j >= last_find ; j--){
                vec[j] = 0;
            }
            last_find = i+1;
        }
    }
    int ans = 0;
    // binary to decimal now : 0010010 : This is the number
    for(int i = 0 ; i<n ; i++){
        ans += vec[i] * ( 1<<i);
    }
    cout<<ans;
    return 0;
}
