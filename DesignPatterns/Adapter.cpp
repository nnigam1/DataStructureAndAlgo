#include<iostream>
using namespace std;

class CefBrowserAdaptee
{
public:
    void initialize(int x)
    {
        cout<<"i am cef initialize with value : "<<x<<endl;
    }
};

class BrowserControl
{
public:
    virtual void initialize() = 0;
};

class CefAdapter :public BrowserControl
{
public:
    void initialize() override {
        adaptee.initialize(10);
    }
private:
    CefBrowserAdaptee adaptee;
};


int main(){
    BrowserControl* browControl;
    browControl = new CefAdapter();
    browControl->initialize();
    return 0;
}
