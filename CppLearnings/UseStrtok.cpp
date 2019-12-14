#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string s = "2017:01:01:23:59:59";

    int n = s.length();
    cout<<strlen(s.c_str())<<endl;
    char str[2];
    strlcpy(str , s.c_str() , n+1);

    string results;
    auto intermediate = strtok(str , ":");

    while( intermediate != NULL)
    {
        results.append(intermediate);
        intermediate = strtok(NULL , ":");
    }

}

