#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n ;
    cin>>n;
    int col;
    cin>>col;

    int row = n/col;
    cout<<row<<endl;
    vector<vector<int>> A(row, vector<int>(col));

    for(int i = 0 ; i< row ; i++){
        for(int j = 0 ; j < col ;j++){
            int y;
            cin>>y;
            A[i][j] = y;
        }
    }
    cout<<endl;
    for(int i = 0 ; i< row ; i++){
        for(int j = 0 ; j < col ;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    int T;
    cin>>T;

    for(int i = 0 ; i<T ; i++){
        int x,y;
        cin>>x;
        cin>>y;
        cout<<A[x][y]<<endl;
    }
    return 0;
}