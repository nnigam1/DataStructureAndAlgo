#include<iostream>
#include<memory>
using namespace std;

class Widget{
    int x;
public:
    Widget(int y): x(y){};
    int getX() const {
        return x;
    }

    void setX(int x) {
        Widget::x = x;
    }
};

void changeX(unique_ptr<Widget>&& uPtr){
    uPtr->setX(30);
    cout<<uPtr->getX()<<endl;
}

int main(){
    unique_ptr<Widget> uPtr(new Widget(20));
    cout<<uPtr->getX()<<endl;
    changeX(move(uPtr));
    cout<<uPtr->getX()<<endl;
    uPtr->setX(40);
    cout<<uPtr->getX()<<endl;
    return 0;
}

