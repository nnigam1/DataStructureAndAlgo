#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "neha Tigam";
    char* dup = strdup(str.c_str());
    char* words = strtok(dup , " ");
    while(words != NULL) {
        cout<<words[0]<<" ";
        words = strtok(NULL , " ");
    }
    free(dup);
return 0;
}
