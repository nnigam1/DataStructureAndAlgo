#include<iostream>
#include<vector>
#include<string>
#include<set>

template<typename T>
T Sum(T a)
{
    return a;
}

template<typename T , typename... Types>
T Sum(T a , Types... args) {
    return a + Sum(args...);
}

template < template<typename , typename...> class ContainerType , typename ValueType , typename... AllocTypes>
void print_container(const ContainerType<ValueType , AllocTypes...>& c)
{
    for( const auto& v : c)
    {
        std::cout<< v <<" ";

    }
    std::cout<<std::endl;
}


int main()
{
    std::cout<< Sum(1,2,3,4,5,6) << std::endl;
    std::cout<<"Let's try printing : string and int sum together"<< std::endl;

    std::string str1 ("Hello");
    std::string str2 = "Hi";

    std::cout<<Sum(str1 , str2 );

    std::cout<<std::endl;

    std::cout<<Sum(1,2,4.5 , 9.0 , 8.9);

    std::set<int> s = {1,2,3,4,5};
    std::vector<int> vec = { 1,2,3 ,4 ,5 , 6};

    print_container(vec);
    print_container(s);
}
