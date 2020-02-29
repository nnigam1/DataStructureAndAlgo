#include<iostream>
#include<string>
using namespace std;

class Entry{
public:
    virtual void print(){
        cout<<"Hello Neha ! i am base"<<endl;
    }
};

class Directory :public Entry {
public:
    void print(){
        cout<<"I am Directory"<<endl;
    }
    string getName(){
        return "Directory1";
    }
};

class File : public Entry {
public:
    void print(){
        cout<<"I am File"<<endl;
    }
    string getName(){
        return "File";
    }
};

int main()
{
   Entry* e = new Directory();
   Directory* d = dynamic_cast<Directory*>(e);
   if( d == nullptr){
       cout<<"Null Directory"<<endl;
   }
   else{
       cout<<d->getName()<<endl;
   }

   File* f = dynamic_cast<File*>(e);
   if( f == nullptr){
       cout<<"Null File"<<endl;
   }
   else {
       cout<<f->getName();
   }
   return 0;
}

