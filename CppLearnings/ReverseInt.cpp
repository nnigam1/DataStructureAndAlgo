#include<iostream>
using namespace std;
#define M 32

int main() {
    unsigned int num = 5;
    unsigned int reverseNum = 0;
   // int size = sizeof(num) * 8;
    for(int i = 0 ; i< M ; i++){
        reverseNum <<= 1;
        reverseNum = reverseNum | num & 1;
        num >>= 1;
    }
    cout<<reverseNum<<endl;
}
