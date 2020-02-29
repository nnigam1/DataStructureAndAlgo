#include<iostream>
#include<memory>
using namespace std;

class Widget : public enable_shared_from_this<Widget>{
    int a ;
    shared_ptr<int> sp1;
public:
    Widget(int x): a(x){}

    shared_ptr<Widget> getWidgetSharedPtr(){
        return shared_from_this();
    }
    shared_ptr<Widget> getWidgetSharedPtr2(){
        return shared_ptr<Widget>(this);
    }

    int getA() const {
        return a;
    }

    void setA(int a) {
        Widget::a = a;
    }
};

void makeCopy(shared_ptr<Widget> sp){
    cout<<sp.use_count()<<endl;
}

int main(){
    shared_ptr<Widget> str1 = shared_ptr<Widget>(new Widget(20));
    cout<<str1.use_count()<<endl;
    makeCopy(str1);
    cout<<str1.use_count()<<endl;
    // Try : making shared ptr with : str1.get() , str1 ,
    shared_ptr<Widget> str2 = shared_ptr<Widget>(str1);
    cout<<str2.use_count()<<endl;
    // it will scan the class and find out the control block
    //of the shared object and allocate the memory.
    shared_ptr<Widget> str3 = str2->getWidgetSharedPtr();
    cout<<str3.use_count()<<endl;
    // if u run getWidgetSharedPtr2 it will make new shared_ptr and send both are pointing to same
    // memory location so one will become dangling
//    shared_ptr<Widget> str4 = str2->getWidgetSharedPtr2();
//    cout<<str4.use_count()<<endl;


    return 0;
}
