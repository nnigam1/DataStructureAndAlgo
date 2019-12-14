#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr , int left , int mid , int right )
{
    int temp[right - left +1];
    int inv_count = 0;

    int i = left;
    int j = mid;
    int k = left;

    while( i<= mid -1 && j <= right)
    {
        if( arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv_count += mid - i;
        }
    }

    while( i <= mid - 1)
        temp[k++] = arr[i++];
    while( j <= right)
        temp[j++] = arr[i++];

    // copy elements back to original vector
    for(int index = left; index <= right ; index++) {
        arr[index] = temp[index];
    }
    return inv_count;
}

int mergerSortUtil( vector<int>& arr , int left , int right)
{
    int inv_count = 0;
    if( right > left)
    {
        int mid = left + ( right - left)/2;

        inv_count += mergerSortUtil(arr  , left , mid );
        inv_count += mergerSortUtil(arr , mid + 1 , right );

        inv_count += merge(arr , left , mid+1 , right);
    }
    return inv_count;
}

int mergeSort(vector<int>& arr)
{
    int n = arr.size();
    return mergerSortUtil(arr , 0 , n-1);
}

// Driver code
int main()
{
    vector<int> arr = {1, 5, 4, 3, 2};
    int ans = mergeSort(arr);
    cout << " Number of inversions are " << ans <<endl;

    for( auto itr : arr)
        cout<<itr<<" ";
    cout<<endl;
    return 0;
}


