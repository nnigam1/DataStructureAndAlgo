#include<iostream>
using namespace std;

auto plusMe = [value=1](int x) {
    return x + value;
};

int main()
{
    cout<<plusMe(42);
    return 0;
}

