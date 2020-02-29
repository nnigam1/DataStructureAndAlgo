// Given N*N board with M rooks placed on it. A rook can only move to kill another rook in same row or column and only one rook can move at given time. There exist a combination of attacks such that number of rooks left on the board are minimum. find this minimum number?
// 4*4
// 1 0 0 1     1 0 0 0
// 0 0 1 0  -> 0 0 1 0
// 0 0 0 0     0 0 0 0
// 0 1 0 1     0 0 0 0



// adjancecy matrix

#include<iostream>
#include<list>
#include<vector>
using namespace std;

#define row 4
#define col 4

list<pair<int,int>> getChilds( vector<vector<int>> matrix , int srow , int scol){
    list<pair<int,int>> result;
    for(int i = 0 ; i< col ; i++){
        if( i != scol) {
            if (matrix[srow][i] == 1) {
                result.push_back({srow, i});
            }
        }
    }
    for(int i = 0; i< row ; i++ ){
        if(i != srow) {
            if (matrix[i][scol] == 1) {
                result.push_back({i, scol});
            }
        }
    }
    return result;
}

void dfs( vector<vector<int>>& matrix, vector<vector<bool>> &visited, int srow, int scol){
    if( visited[srow][scol])
        return;

    visited[srow][scol] = true;
    auto childList = getChilds(matrix, srow , scol);
    for( auto itr : childList){
        cout<<itr.first<<" "<<itr.second<<endl;
        matrix[itr.first][itr.second] = 0;
        dfs(matrix, visited , itr.first , itr.second);
    }
}


int main(){
    vector<vector<int>> matrix = { {1, 0, 0, 1},
                             {0,0,1,0},
                             {0,0,0,0},
                             {0,1,0,0}};
    //cout<<matrix[0][0]<<endl;
    vector<vector<bool>> visited(row, vector<bool>(col , false));
    for(int i = 0 ; i< row ; i++){
        for(int j = 0 ; j < col ; j++)
        {
            if( matrix[i][j] == 1){
                dfs(matrix,visited, i , j);
            }
        }
    }

    int count = 0;
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j< col ; j++)
        {
            if( matrix[i][j] == 1){
                count++;
            }
        }
    }
    cout<<count<<" ";
    return 0;
}


