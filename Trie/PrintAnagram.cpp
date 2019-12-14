#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

// using the fact that map is always sort.
string getKey(string str)
{
    string res = "";
    map<char,int> count;
    for( int i=0;i<str.length();i++)
    {
        count[str[i]]++;
    }
    for( auto& itr : count) {
        while( itr.second > 0) {
            res += itr.first;
            itr.second--;
        }
    }

    return res;
}

int main()
{
    string word[] = {"caat", "doooog", "tac", "god", "aact", "gdo"};
    map<string, vector<string> > mp;
    int n = sizeof(word)/sizeof(word[0]);
    for(int i=0;i<n;i++)
    {
        mp[getKey(word[i])].push_back(word[i]);
    }

    for(auto it =mp.begin();it!=mp.end();it++)
    {
        for(auto it2 =it->second.begin(); it2!=it->second.end();it2++)
        {
            cout<<*it2<<" ";
        }
        cout<<endl;
    }

    return 0;
}


