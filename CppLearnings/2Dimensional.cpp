#include<iostream>
using namespace std;

int main()
{
    int** arr;
    *arr = new int[4];
    for(int i = 0 ; i<4 ; i++)
    {
        arr[i] = new int[4];
    }

    for(int i = 0 ; i< 4 ; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    arr = NULL;

}
