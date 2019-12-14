#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void forEach(std::vector<int>& vec ,const std::function<void(long)> &func)
{
    std::for_each(vec.begin() , vec.end() , func);
}

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7};
    auto it = std::find_if(vec.begin() , vec.end() , [](const int i ) {
        return i >= 3;
    } );
    std::cout<<*it << std::endl;

    int a = 5 ;

    auto myFunc = [=](int val) {
        std::cout<<"value = "<<val<<std::endl;
    };

//    auto myFunc2 = [=](long val) {
//        std::cout<<"value = "<<std::endl;
//    };

    forEach(vec , myFunc);

    return 0;
}
