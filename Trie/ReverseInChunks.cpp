#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

void countPalindrome(string basicString);

using namespace std;

int main()
{
    string str = "abbaeae";
    countPalindrome(str);
    return 0;
}

void countPalindrome(string basicString) {
    int len = basicString.length();
    unordered_map<string , int> palindromeSubStringMap;
    for(int i = 1; i < len ; i++)
    {
        int low = i-1;
        int high = i;
        while( low>=0 && high<len && basicString[low] == basicString[high]) {
            palindromeSubStringMap[basicString.substr(low, high-low+1)] =  high - low +1;
            --low;
            ++high;
        }
        low = i-1;
        high = i+1;
        while(low >= 0 && high < len && basicString[low] == basicString[high]) {
            palindromeSubStringMap[basicString.substr(low, high-low+1)] = high - low +1;
            --low;
            ++high;
        }
    }

    for( auto itr : palindromeSubStringMap) {
        cout<<itr.first<<" "<<itr.second<<" ";
        cout<<endl;
    }

}

