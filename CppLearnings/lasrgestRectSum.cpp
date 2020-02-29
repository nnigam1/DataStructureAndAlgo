#include<iostream>
#include<vector>
using namespace std;

int kadane(vector<int> temp, int& top , int& bottom ){
    int x = 0;
    bottom = -1;
    int max_so_far = numeric_limits<int>::min();
    int max_end_here = 0;
    int n = temp.size();
    for(int i = 0 ; i < n ; i++){
        max_end_here += temp[i];
        if( max_end_here < 0)
        {
            max_end_here = 0;
            x = i+1;
        }
        if( max_so_far < max_end_here) {
            max_so_far = max_end_here;
            top = x;
            bottom = i;
        }
    }

    if( bottom != -1)
        return max_so_far;

    max_so_far = temp[0];
    top = bottom = 0;
    for(int i = 1 ; i< n ; i++){
        if( max_so_far < temp[i])
        {
            max_so_far = temp[i];
            top = bottom = i;
        }
    }
    return max_so_far;
}

int main()
{
    vector<vector<int>> vec {{1,2,-1,-4,-20} ,
                             {-8, -3, 4, 2, 1},
                             {3, 8, 10, 1, 3},
                             {-4, -1, 1, 7, -6}};

    int COL = vec[0].size();
    int ROW = vec.size();

    int maxSum = numeric_limits<int>::min();
    int maxLeft , maxRight , maxTop , maxBot;

    for( int left = 0 ; left < COL ; ++left){
        vector<int> temp( ROW , 0);
        int k = 0;
        for(int right = left ; right < COL ; right++){
            for(int i =0 ; i < ROW ; i++) {
                temp[i] += vec[i][right];
            }
                int top , bot = 0;
                int sum = kadane(temp, top , bot);
                if( sum > maxSum){
                    maxSum = sum;
                    maxLeft = left;
                    maxRight = right;
                    maxTop = top;
                    maxBot = bot;
            }
        }
    }
    cout<<maxSum<<endl;
    cout<<maxTop<<" "<<maxLeft<<" "<<maxBot<<" "<<maxRight<<endl;
    return 0;
}
