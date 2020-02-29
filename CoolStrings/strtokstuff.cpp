#include<iostream>
#include<string>
using namespace std;

void convert(string str)
{
    char* pch = NULL;
    string convertedStr;
    int n = str.length();
    char tokenStr[n];
    strlcpy(tokenStr , str.c_str() , n+1);

    pch = strtok(tokenStr , ".");
    while(pch != NULL)
    {
        convertedStr.append(pch);
        pch = strtok(NULL , ".");
        if( pch != NULL)
        {
            convertedStr.append("[.]");
        }
    }
    cout<<convertedStr<<endl;
    cout<<sizeof(convertedStr)<<endl;
}

int main()
{
    int T;
    while( T != -1) {
        cin>>T;
        string str;
        cin >> str;
        convert(str);
    }
    return 0;
}
