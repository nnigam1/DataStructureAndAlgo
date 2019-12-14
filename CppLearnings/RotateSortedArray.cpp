#include<iostream>
using namespace std;

/* Standard Binary Search function*/
int binarySearch(int arr[], int low,
                 int high, int key)
{
   if(high < low )
       return -1;
   int mid = low + (high - low )/2;
   if( arr[mid] == key)
       return mid;
   if( arr[mid] > key)
       return binarySearch(arr , low , mid -1 , key);
   return binarySearch(arr , mid+1 , high , key);
}

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2
   it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high)
{
    if( high < low)
        return -1;

    int mid = low + (high - low)/2;
    if(mid < high && arr[mid] > arr[mid+1])
        return mid;
    if( mid > low && arr[mid-1] > arr[mid])
        return mid-1;
    if( arr[low] >= arr[mid])
        return findPivot(arr , low, mid -1);
    return findPivot(arr , mid+1 , high);
}

/* Searches an element key in a pivoted
   sorted array arr[] of size n */
int pivotedBinarySearch(int arr[], int n, int key)
{
    int index = findPivot(arr, 0 , n);
    cout<<index<<" ";

    if( index == -1)
        return binarySearch(arr , 0 , n , key);

    if( arr[0] > key)
        return binarySearch(arr , index+1 , n , key);
    return binarySearch(arr , 0 , index - 1 , key);
}

int moreEffectiveSearch(int* arr ,int low , int high , int key)
{
    if( high < low )
        return -1;

    int mid = low + (high - low)/2;
    if ( arr[mid] == key)
        return mid;
    if(arr[low] <= arr[mid])
    {
        if( key >= arr[low] && key <= arr[mid])
            return binarySearch(arr , low , mid -1 , key);
        return binarySearch(arr , mid+1 , high , key);
    }

    if(key >= arr[mid] && key <= arr[high])
        return binarySearch(arr , mid+1, high, key);
    return binarySearch(arr , low , mid - 1, key);
}

/* Driver program to check above functions */
int main()
{
    // Let us search 3 in below array
    int arr1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2 , 0, 2};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int key = 0;

    // Function calling
    cout << "Index of the element is : " <<
         pivotedBinarySearch(arr1, n, key)<<endl;

    cout<<moreEffectiveSearch(arr1 , 0 , n , key )<<endl;

    return 0;
}
