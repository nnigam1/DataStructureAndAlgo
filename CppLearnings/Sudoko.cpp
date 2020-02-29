#include<iostream>
using namespace std;

#define N 9

bool FindUnassignedLocation(int grid[N][N] , int& row , int& col){
    for(int i = 0 ; i< N ; i++){
        for(int j = 0 ; j < N ; j++){
            if( grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool UsedInRow(int grid[N][N] , int row , int num){
    for(int i = 0 ; i < N ; i++){
        if( grid[row][i] == num){
            return true;
        }
    }
    return false;
}

bool UsedInCol(int grid[N][N] , int col , int num){
    for(int i = 0 ; i < N ; i++){
        if( grid[i][col] == num){
            return true;
        }
    }
    return false;
}

bool UsedInBox(int grid[N][N] , int boxStartRow , int boxStartCol , int num){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3; j++){
            if( grid[boxStartRow + i][boxStartCol + i] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N] , int row , int col ,int num){
    if (!UsedInRow(grid , row , num) &&
            !UsedInCol(grid , col , num) &&
            !UsedInBox(grid , row - row%3 , col - col%3 , num) ){
        return true;
    }
    return false;
}

bool solveSudoku(int grid[N][N]){
    int row , col;
    if(!FindUnassignedLocation(grid, row , col))
        return true;

    for(int num = 1; num <=9 ; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void printSudoku(int grid[N][N]){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < N ; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int grid[N][N] = {{0, 5, 8, 0, 3, 0, 4, 0, 0},
                      {6, 0, 2, 0, 0, 9, 0, 0, 5},
                      {0, 0, 0, 4, 0, 5, 0, 2, 0},
                      {8, 0, 9, 0, 1, 0, 0, 0, 0},
                      {5, 0, 3, 0, 9, 0, 2, 0, 1},
                      {0, 0, 0, 0, 8, 0, 3, 0, 7},
                      {0, 8, 0, 3, 0, 7, 0, 0, 0},
                      {1, 0, 0, 9, 0, 0, 7, 0, 3},
                      {0, 0, 7, 0, 2, 0, 5, 4, 0}};

    if( solveSudoku(grid)) {
        cout << "Yay! Sudoku solved !!!"<<endl;
        printSudoku(grid);
    }
    else
        cout<<"Not Possible";
    return 0;
}

