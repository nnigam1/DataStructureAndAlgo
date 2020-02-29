#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool dfs(int start , vector<bool>& visited , int sum , bool isFirstTurn , int total , int n , bool& secondWin){
cout<<endl;
    visited[start] = true;
    cout<<"sum : "<<sum<<" isfirstTurn : "<<isFirstTurn;
    if( sum >= total) {
        if (isFirstTurn) {
            return true;
        } else {
            secondWin = true;
            return false;
        }
    }

    for(int i = 1 ; i<=n ; i++){
        if(visited[i] == false ) {
            int temp = n;
            if( visited[temp] == false && sum+temp >= total) {
                cout<<" Trying with maximum : "<<temp<<endl;
                isFirstTurn = !isFirstTurn;
                if( isFirstTurn)
                {
                    return true;
                } else{
                    secondWin = true;
                    return false;
                }
              }
            sum+=i;
             if( secondWin)
                 return false;
             else if(dfs(i , visited , sum , !isFirstTurn , total , n , secondWin))
                 return true;

        }
    }
    visited[start] = false;
    sum-=start;
    return false;
}

bool canIWin(int n , int total)
{
    vector<bool> visited(n+1 , false);
    bool secondWin = false;
    visited[1] = true;
    if(dfs( 1 , visited , 1 , true , total , n , secondWin))
    {
        if(secondWin)
            return false;
        return true;
    }
    return false;
}

int main(){
    int n = 14;
    int total = 10;

    if(canIWin(n ,total))
    {
        cout<<endl;
        cout<<"Yes !!!, i can win"<<endl;
    }
    else{
        cout<<endl;
        cout<<"Try Next Time !"<<endl;
    }
    return 0;
}

