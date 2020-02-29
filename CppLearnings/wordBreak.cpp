#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

int main()
{
    set<string> dict {"cat", "cats", "and", "sand", "dog" , "eee" };
    //set<string> dict{"programcree","program","creek"};
   string str = "catsanddog";
  // string str = "programcreek";
    int start = 0;
    int size = str.length();
    vector<pair<bool , string>> vec(size+1);
    vec[0] = {true,""};

    for(int i = 0 ; i< str.length() ; i++) {
        if(!vec[i].first)
            continue;
        for( string a : dict) {
            int len = a.length();
            int end = i + len;
            if( end > str.length()) {
                continue;
            }
            if(vec[end].first)
                continue;

            string str2 = str.substr(i , end -i );
            bool match = str2 == a;
             if( match) {
                vec[end] = {true ,str2};
            }
        }
    }
    for( auto itr : vec) {
        cout<<itr.first<<" "<<itr.second<<" ";
    }
    cout<<endl;
    cout<<str.length()<<endl;
    //cout<<vec[str.length() ]<<endl;
    return 0;
}
