#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<list>
using namespace std;

int main()
{
    set<string> dict {"cat", "cats", "and", "sand", "dog" , "eee" };
   // set<string> dict{"programcree","program","creek"};
    string str = "catsanddogeee";
    //string str = "programcreek";
    int start = 0;
    int size = str.length();
    vector<list<string>> vec(size+1);
    vec[0].push_back("null");

    for(int i = 0 ; i< str.length() ; i++) {
        if(vec[i].size() == 0) {
            continue;
        }
        for( string a : dict) {
            int len = a.length();
            int end = i + len;
            if( end > str.length()) {
                continue;
            }

            string str2 = str.substr(i , end -i );
            bool match = str2 == a;
            if( match) {
                vec[end].push_back(str2);
            }
        }
    }
    for( int i = 0 ; i < vec.size() ; i++) {
        cout<<i<<"->";
        for( auto itr : vec[i]) {
            cout<<itr<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<str.length()<<endl;
    //cout<<vec[str.length() ]<<endl;
    return 0;
}
