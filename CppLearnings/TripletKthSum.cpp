#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {4,3,2,5,5};
    sort(arr.begin() , arr.end());
    int count = 0;
    int temp = 0;
    int k = 10;
    int len = arr.size();
    int i , j = 0;
    for(i = 0; i < len-2 ; i++){
        for(j = i+2 ; j < len ; j++) {
            temp = count;
            count+=(len -j);
            if( count > k)
            {
                break;
            }
        }
    }

    int a = arr[i-1];
    int b = arr[i];
    for( int j = i+1 ; j < len ; j++){
            temp++;
            if( temp == k){
                cout<<a<<" "<<b<<" "<<arr[j]<<endl;
            }
    }
    return 0;
}

