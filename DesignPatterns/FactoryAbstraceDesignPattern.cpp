// This is one factory , now suppose we have one more class known as BrowserStuff
// and that also have variants as cef BrowserStuff and IE browserStuff
// we can actually create one more stuff factory from AbsFactory
// and use it so abstract factory produces factory ,
// factory produces product.

#include<iostream>
using namespace std;

enum BrowserType {CEF , IE };

class Browser
{
public:
    virtual void printBrowserName() = 0;
};

class CefBrowser : public Browser
{
public:
    void printBrowserName()
    {
        cout<<"I am Cef Browser"<<endl;
    }
};

class IEBrowser : public Browser
{
public:
    void printBrowserName()
    {
        cout<<"I am an IE Browser"<<endl;
    }
};

class AbsFactory
{
public:
    virtual Browser* createBrowser(BrowserType type) = 0;
};

class Factory : public AbsFactory
{
public:
    Browser* createBrowser(BrowserType type) override {
        if( type == BrowserType::CEF)
        {
            return new CefBrowser();
        } else if (type == BrowserType ::IE)
        {
            return new IEBrowser();
        }
        return NULL;
    }
};

int main()
{
    AbsFactory* fact;
    Browser* br;

    fact = new Factory();
    br = fact->createBrowser(BrowserType::CEF);
    br->printBrowserName();
    return 0;
}


