#include<iostream>
using namespace std;

class S {
    int x;

private:
    S()= default;
    ~S()= default;
    S( const S& obj) = delete;
    S& operator=(const S& obj) = delete;
    S( const S&& obj) = delete;
    S& operator=(const S&& obj) = delete;
public:
     static S* getInstance()
     {
         static S instance;
         return &instance;
     }

    int getX() const {
        return x;
    }

    void setX(int x) {
        S::x = x;
    }

};

int main()
{
    S* s1 = S::getInstance();
    s1->setX(20);
    S* s2 = s1;
    S* s3 = S::getInstance();
    S* s4 = move(s1);
    cout<<s2->getX()<<" "<<s1->getX()<<" "<<s3->getX()<<" "<<s4->getX()<<endl;
    return 0;
}
