#include<iostream>
#include<string>
#include<memory>
using namespace std;

void printToken(string str)
{
    char* pch;
    string str2;
    cout<< sizeof(pch)<<endl;
    cout<< sizeof(str)<<endl;
    int n = str.length();
    cout<<n<<endl;
    char tokStr[n];
   // strcpy(tokStr , str.c_str());
   strlcpy(tokStr , str.c_str() , n+1);
    cout<<strlen(tokStr)<<endl;
    pch = strtok(tokStr , ".");
    while(pch != NULL)
    {
        str2.append(pch);
        pch = strtok(NULL ,".");
        if( pch != NULL)
        {
            str2.append("[.]");
        }
    }
    cout<<str2<<endl;
}
void getString()
{
  //  char* str = "neha nigam";
   //char str[11] = "neha nigam";
   //char* str = new char[11];
  // str[0] = 'h';
   //str[1] = 'i';
//  unique_ptr<char> uq( new char('h')); unique ptr for only char
//  cout<<uq<<endl;

    int buf = 11;
    auto uq = make_unique<char[]>(buf); // array of char*
    uq[0] = 'h';

    cout<<uq<<endl;

  //return uq;
}

int main()
{
    string str = "255.255.1.0";
    printToken(str);
    char str2[4] = "avh";
    str2[2] = 'o';
    cout<<str2<<endl;
    getString();
    cout<<sizeof(str2)<<endl;

    return 0;
}
