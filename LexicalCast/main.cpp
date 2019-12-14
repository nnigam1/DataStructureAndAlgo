#include <iostream>

class MainAccess {
public:
    MainAccess(int myAccess) : myAccess(myAccess) {}


private:
    int myAccess;
public:
    friend std::ostream &operator<<(std::ostream &os, const MainAccess &access) {
        os << "myAccess: " << access.myAccess;
        return os;
    }

public:
    int getMyAccess() const {
        return myAccess;
    }

    void setMyAccess(int myAccess) {
        MainAccess::myAccess = myAccess;
    }


};

int main() {

    int x = 5;
    //std::string str = lexical_cast<std::string >(x);



    return 0;
}