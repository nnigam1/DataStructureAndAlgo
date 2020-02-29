#include<iostream>
#include<vector>
using namespace std;


class Point{
public:
    friend ostream &operator<<(ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }

public:
    int x;
    int y;
};

int rectSum(Point topLeft , Point botRight , vector<vector<int>> vec){
    int curr_sum = 0;
    for(int i = topLeft.x ; i <= botRight.x ; i++ ){
        for(int j = topLeft.y ; j <= botRight.y ; j++){
            curr_sum+= vec[i][j];
        }
    }
    return curr_sum;
}

int main(){
    vector<vector<int>> vec {{1,2,-1,-4,-20} ,
                             {-8, -3, 4, 2, 1},
                             {3, 8, 10, 1, 3},
                             {-4, -1, 1, 7, -6}};

    int COL = vec[0].size();
    int ROW = vec.size();

//    vector<vector<int>> vec = {{1,0,1} ,
//                               {0,-2,3}};

    Point maxLeftFinal;
    Point maxRightFinal;
    int maxSum = numeric_limits<int>::min();
    int curr_sum = 0;
    int k = 2;

    for(int row = 0 ; row< ROW ; row++){
        for(int left = 0 ; left < COL ; left++){
            Point pointLeft = {row , left};
            for(int row = 0 ; row < ROW ; row++){
                for( int right = left ; right < COL ; right++){
                    Point pointRight = {row, right};
                    int sum = rectSum(pointLeft , pointRight , vec);
                    if (maxSum < sum ){
                        maxSum = sum;
                        maxLeftFinal = pointLeft;
                        maxRightFinal = pointRight;
                    }
                }
            }
        }
    }
    cout<<maxSum<<endl;
    cout<<maxLeftFinal<<" "<<maxRightFinal<<endl;
    return 0;
}

