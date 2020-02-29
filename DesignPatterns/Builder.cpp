#include<iostream>
#include<string>
using namespace std;

class Browser
{

private:
    string jSUrl;
    int count;
    string type;
    string name;

public:
    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        Browser::type = type;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Browser::name = name;
    }

    const string &getJsUrl() const {
        return jSUrl;
    }

    void setJsUrl(const string &jSUrl) {
        Browser::jSUrl = jSUrl;
    }

    int getCount() const {
        return count;
    }

    void setCount(int count) {
        Browser::count = count;
    }

    Browser(const string &jSUrl, int count, const string &type, const string &name) : jSUrl(jSUrl), count(count),
                                                                                      type(type), name(name) {}
};

class BrowserBuilder
{
public:
    BrowserBuilder* setJsUrl(const string &jSUrl) {
        BrowserBuilder::jSUrl = jSUrl;
        return this;
    }

    BrowserBuilder* setCount(int count) {
        BrowserBuilder::count = count;
        return this;
    }

    BrowserBuilder* setType(const string &type) {
        BrowserBuilder::type = type;
        return this;
    }

    BrowserBuilder* setName(const string &name) {
        BrowserBuilder::name = name;
        return this;
    }

    Browser* getBrowser()
    {
        return new Browser(jSUrl , count , type , name);
    }

private:
    string jSUrl;
    int count;
    string type;
    string name;
};


int main()
{
    BrowserBuilder* bb = new BrowserBuilder();
    Browser* b = bb->setName("cef")->setType("CEF")->setCount(2)->getBrowser();
    cout<<b->getCount();
    return 0;
}
