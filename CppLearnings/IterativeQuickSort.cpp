#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int partition(int arr[] , int l , int h) {
    int pivot = arr[h];
    int i = l - 1;
    for(int j = l ; j < h ; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[j] , arr[i]);
        }
    }
    swap(arr[i] , arr[h]);
}

void quickSortIterative(int arr[] , int l , int h) {
    stack<int> st;
    st.push(l);
    st.push(h);
    while(!st.empty()) {
         h = st.top();
        st.pop();
         l = st.top();
        st.pop();
        int p = partition(arr , l , h);
        if( p - 1 > l){
            st.push(l);
            st.push(p-1);
        }
        if( p + 1 < h){
            st.push(p+1);
            st.push(h);
        }
    }
}

int main() {
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSortIterative(arr , 0 , n-1);
    for(int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
