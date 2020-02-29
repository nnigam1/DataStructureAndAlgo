#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        string result = S;
        int diff = 0;
        map<int , pair<string, string>> destSourceMap;
        for(int i = 0 ; i <n ; i++)
        {
            destSourceMap.insert({indexes[i] , {sources[i] , targets[i]}});
        }

        for(auto itr : destSourceMap)
        {
            int pos = itr.first;
            string source = itr.second.first;
            string dest = itr.second.second;
            int srcIndex = S.find(source);
            int index = result.find(source);
            while(srcIndex != string::npos)
            {
                if( srcIndex == pos)
                    break;
                srcIndex = S.find(source, srcIndex+1);

            }
            if( srcIndex != string::npos && srcIndex == pos )
            {
                while(index != string::npos)
                {
                    if( index == pos+diff)
                        break;
                    index = result.find(source , index+1);
                }
                if( index != string::npos && index == pos + diff)
                {
                    result.replace(index ,source.length() , dest);
                    int len1 = source.length();
                    int len2 = dest.length();
                    if( len1 >= len2)
                    {
                        diff = diff - ( len1 - len2);
                    }
                    else
                    {
                        diff = diff + ( len2 - len1);
                    }
                }
            }
        }
        return result;
    }
};

//inputs :
//"jjievdtjfb"
//[4,6,1]
//["md","tjgb","jf"]
//["foe","oov","e"]
//
//"ejvzndtzncrelhedwlwiqgdbdgctgubzczgtovufncicjlwsmfdcrqeaghuevyexqdhffikvecuazrelofjmyjjznnjdkimbklrh"
//[25,35,60,77,69,79,15,19,58,92,27,64,4,11,51,7,72,67,30,0,74,98,17,85,48,32,38,62,43,2,9,55,87]
//["gc","tov","vy","re","ikv","lo","dw","iqgdbd","ue","kimbk","tgu","qd","ndt","elhe","crq","zn","ec","ff","bz","ej","ua","rh","lw","jj","mfd","cz","ufn","ex","cjl","vz","cr","agh","znnj"]
//["dxs","hn","vfc","wnr","tira","rko","oob","mlitiwj","zrj","onpp","ot","c","lm","hbsje","dgc","ruf","qi","h","vzn","ja","ow","te","km","imq","pia","ixp","xsod","m","eat","yf","lzu","dgy","dyrsc"]
//
//"wreorttvosuidhrxvmvo"
//[14,12,10,5,0,18]
//["rxv","dh","ui","ttv","wreor","vo"]
//["frs","c","ql","qpir","gwbeve","n"]






