#include<iostream>
#include<set>
#include<tuple>
using namespace std;

const int ROW = 5;
const int COL = 5;

bool isInsideGrid(int i, int j)
{
    return (i >= 0 && i < COL && j >= 0 && j < ROW);
}

int shortest(int pInt[5][5]) {
    int dist[ROW][COL];
    for( int i = 0 ; i< ROW ; i++)
    {
        for(int j = 0 ; j<COL ; j++)
        {
            dist[i][j] = std::numeric_limits<int>::max();
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    set<tuple<int,int,int>> s;

    s.emplace(pInt[0][0] , 0 , 0);

    dist[0][0]= pInt[0][0];

    while( !s.empty())
    {
        tuple<int, int , int> temp = *s.begin();
        s.erase(temp);

        int x = get<1>(temp);
        int y = get<2>(temp);

        // to iterate over all the neighbours of this cell.
        for(int i = 0 ; i<4; i++)
        {
            int x2 = x + dx[i];
            int y2 = y + dy[i];

            if(!isInsideGrid(x2, y2))
                continue;

            if( dist[x][y] + pInt[x2][y2] < dist[x2][y2])
            {
                if( dist[x2][y2] != std::numeric_limits<int>::max())
                {
                    s.erase({dist[x2][y2] , x2, y2});
                }

                dist[x2][y2] = dist[x][y] + pInt[x2][y2];
                s.emplace(dist[x2][y2] , x2, y2);
            }
        }

    }

return dist[ROW -1][COL -1];

}

// Driver code to test above methods
int main()
{
    int grid[ROW][COL] =
            {
                    31, 100, 65, 12, 18,
                    10, 13, 47, 157, 6,
                    100, 113, 174, 11, 33,
                    88, 124, 41, 20, 140,
                    99, 32, 111, 41, 20
            };

    cout << shortest(grid) << endl;
    return 0;
}


