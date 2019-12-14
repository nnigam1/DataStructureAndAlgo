#include<iostream>
#include <regex>
#include<string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    regex pat("abc");
    bool match = regex_search(str, pat);

    char c = '@';
    cout<<ispunct(c);

    match ? cout << "\nMatch Found\n" : cout << "Match Not Found\n";


}

