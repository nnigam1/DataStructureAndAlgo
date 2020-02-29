#include<iostream>
#include<vector>
using namespace std;

int maxHole2(vector<int> vec , int w){
    int len = vec.size();
    vector<int> preSum(len + 1 , 0);

    for(int i = 0 ; i < len ; i++){
        preSum[i+1] = vec[i] + preSum[i];
    }

    vector<int> left2right(len , 0);
    vector<int> right2left(len , 0);

    for(int i =w ; i < len ; i++){
        left2right[i] = max(left2right[i-1] , preSum[i] - preSum[i-w]);
    }

    for(int i = len - w; i>=0; i--){
        right2left[i] = max(right2left[i+1] , preSum[i+w] - preSum[i]);
    }

    int maxi = INT_MIN;
    for(int i = 0 ; i< len ; i++){
        maxi = max(left2right[i] + right2left[i] , maxi);
    }
    return maxi;
}



int main(){
    vector<int> vec = {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0};
    int w = 5;
    int len = vec.size();
    int start = 0;
    int count = 0;
    int maxi = INT_MIN;
    for(int i = 0 ; i < len ; i++){
        if( i - start >= w ){
            if(vec[start] == 1){
                count--;
            }
            start++;
        }
        if(vec[i] == 1)
            count++;
        maxi = max(maxi , count);
    }
    cout<<maxi<<endl;
    cout<<maxHole2(vec , w)<<endl;
    return 0;
}

