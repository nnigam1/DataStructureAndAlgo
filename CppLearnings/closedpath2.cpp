#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point{
public:
    int x , y;
    friend ostream &operator<<(ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

int dist(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(Point p1, Point p2 ,Point r1){
    int val = (p2.y - p1.y) * (r1.x - p2.x) - (r1.y - p2.y) * (p2.x - p1.x);
    if( val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void printClosedPath(vector<Point> points){
    int sz = points.size();
    int min = 0;
    for(int i = 1; i < sz ; i++){
        if( points[i].y == points[min].y && points[i].x < points[min].x){
            min = i;
        }
        else if( points[i].y < points[min].y)
        {
            min = i;
        }
    }

    swap(points[0] , points[min]);
    std::sort(points.begin() + 1, points.end() , [points](const Point p1 ,const Point p2 ){
            int o = orientation(points[0] , p1, p2 );
            if( o == 0)
            {
                return (dist(points[0] , p2) >= dist(points[0] , p1)) ? -1 : 1;
            }
            return ( o == 2) ? -1 : 1;
    });

//    sort(points.begin() , points.end(), [](Point a, Point b){
//        return a.y < b.y;
//    });

    for(auto itr : points){
        cout<<itr<<endl;
    }
}

int main(){
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                             {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    printClosedPath(points);
    return 0;
}


