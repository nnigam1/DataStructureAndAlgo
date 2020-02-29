#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int partition(vector<int>& vec , int l , int r) {
    int pivot = vec[r];
    cout<<"pivot : "<<pivot<<endl;
    int i = l ;
    for(int j = l ; j <= r-1 ; j++) {
        if(vec[j] <= pivot) {
            swap(vec[i] , vec[j]);
            i++;
        }
    }
    swap(vec[i] , vec[r]);
    return i;
}

int kthSmallest(vector<int> vec , int l , int r , int k) {
    if( l < r) {
        cout<<"l : "<<l<<" r : "<<r<<endl;
        int index = partition(vec, l, r - 1);
        cout << "index : " << index << " " << endl;
        for (auto itr : vec) {
            cout << itr << " ";
        }
        cout << endl;
        if (index == k - 1) {
            cout << vec[index] << endl;
            return vec[index];
        } else if (index < r && index < k - 1) {
            return kthSmallest(vec, index + 1, r - 1, k);
        } else {
            return kthSmallest(vec, l, index , k);
        }
    }
    return -1;
}

int main() {
    vector<int> vec = { 10, 4, 5, 8, 6, 11, 26 , 32 , 56 , 90 };
  //  vector<int> vec = { 5, 4 , 3 , 2 , 1 };
    int k = 6;
    cout<<kthSmallest(vec ,0 , vec.size() , k);
    cout<<endl;
}
