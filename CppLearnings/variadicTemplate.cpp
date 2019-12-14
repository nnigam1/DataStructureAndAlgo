#include<iostream>
#include<vector>

template<typename T>
void Print(T a)
{
    std::cout<< a << std::endl;
}

template<typename T , typename... Types>
void Print(T a , Types... args )
{
    std::cout<< a<< std::endl;
    Print(args...);
}

int main()
{
    std::vector<int> vec = { 1,2 , 3,4, 5, 6};
    std::cout<<"Print in Int"<<std::endl;

    Print(1,2,3,4,5,6);
    std::cout<<"Print in float"<<std::endl;

    Print(1.1 , 2.3 , 8.9 , 9.0 , 4,5);

    std::cout<<"Let's try Printing  in Mix"<<std::endl;

    Print( 1, 1.1 , "Hello" , "Hi" , "new" , 3.5 , 9 );
    return 0;
}