#include<iostream>
#include<tuple>
#include<queue>
#include<map>
using namespace std;

#define ROW 4
#define COL 5

int getMinval(int mat[ROW][COL] , int A , int B , int C , int D)
{

    queue<tuple<int, int> > q;

    int  level = 0;
    int count = 0;
    int min_level = INT_MAX;
    q.push(make_tuple(A, B));
    q.push(make_tuple(-1, -1));
    map<pair<int , int> , bool> m;
    m[pair<int, int>(A, B)] = true;

    while (!q.empty())
    {
        tuple<int, int> temp = q.front();
        q.pop();

        int first = get<0>(temp);
        int second = get<1>(temp);

        if (first == -1 && second == -1)
        {
            level++;
            if (q.empty())
            {
                if (min_level == INT_MAX)
                {
                    return -1;
                }
                else
                    return min_level;
            }
            else
            {
                temp = q.front();
                q.pop();
                int first = get<0>(temp);
                int second = get<1>(temp);
                q.push(make_tuple(-1, -1));
            }
        }

        // if value matches.
        if ( first == C  && second == D)
        {
            if (min_level > level)
            {
                min_level = level;
            }
        }

        if (first != -1 && second != -1)
        {

            for (int i = first + 1; i < ROW; i++) {
                if (mat[i][second] == 1)
                {
                    break;
                }
                else
                {
                    if (m.find(make_pair(i, second)) == m.end())
                    {
                        m[make_pair(i, second)] = true;
                        q.push(make_tuple(i, second));
                    }
                }
            }
            for (int j = second + 1; j < COL; j++) {
                if (mat[first][j] == 1)
                {
                    break;
                }
                else
                {
                    if (m.find(make_pair(first, j)) == m.end())
                    {
                        m[make_pair(first, j)] = true;
                        q.push(make_tuple(first, j));
                    }
                }
            }
        }
    }
    if (min_level == INT_MAX)
    {
        return -1;
    }
    return -1;
}


int main()
{
    int Mat[4][5] = { { 0, 0, 0, 1 ,0 },
                      { 0, 0, 0, 1,1 },
                      { 1, 1, 0, 0,0 },
                      { 0, 1, 0, 0,0 } };

    int A = 0, B = 0, C = 3, D = 4;

    cout << getMinval(Mat, A, B, C, D) << endl;
    return 0;
}

