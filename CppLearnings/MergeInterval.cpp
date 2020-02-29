#include<iostream>
#include<vector>
using namespace std;

int main()
{
    using ipair = pair<int , int>;
    int start = 0 ;
    int end = 0;
    vector<pair<int , int>> vec = {{1,3} ,{1,9} , {2,12} , {8,10} ,{2,6},{16,17} ,{15,18}  , {9, 11} , {19,21}};
    vector<ipair > result;
    sort(vec.begin() , vec.end() , [](ipair a , ipair b){
        if( a.first == b.first)
            return a.second < b.second;
       return a.first < b.first;
    });

    for( auto itr : vec) {
        cout << "[" << itr.first << " " << itr.second << "]";
    }
    cout<<endl;
    int n = vec.size();
    start = vec[0].first;
    end = vec[0].second;
    for(int i = 1; i <= n ; i++) {
        if( i == n){
            result.push_back({start, end});
            break;
        }
        if( end < vec[i].first) {
            result.push_back({start, end});
            start = vec[i].first;
            end = vec[i].second;
        }
        else {
            end = max(end , vec[i].second);
        }
    }

    for( auto itr : result) {
        cout << "[" << itr.first << " " << itr.second << "]";
    }
    cout<<endl;
    return 0;
}

