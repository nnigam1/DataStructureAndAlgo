#include<iostream>
using namespace std;

// trailing return type syntax , decltype check the type of expression.
template <typename T1 , typename T2>
auto addIt(T1 a , T2 b) -> decltype(a+b)
{
    return a+b;
}

int main() {
    constexpr int x = 4;
    constexpr int y = 5;
    static_assert( x != y , "x!=y");
    auto d = {9};
    for( auto itr : d)
        cout<<itr<<endl;
    cout<< addIt(1 , 1.8)<<endl;
    cout<< addIt(1.8 , 1);


    return 0;

}
