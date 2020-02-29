#include<iostream>
#include<list>
using namespace std;

class Directory;
class File;

class Entry{
public:
    int getId() const {
        return id;
    }

    void setId(int id) {
        Entry::id = id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Entry::name = name;
    }

    long getLastUpdated() const {
        return lastUpdated;
    }

    void setLastUpdated(long lastUpdated) {
        Entry::lastUpdated = lastUpdated;
    }

    virtual int getSize() = 0;

private:
    int id;
    string name;
    long lastUpdated;
    long size;

};

class File : public Entry{

private:
    string contents;
    int size;

public:
    const string &getContents() const {
        return contents;
    }

    void setContents(const string &contents) {
        File::contents = contents;
    }

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        File::size = size;
    }

};

class Directory : public Entry{
public:
    int size;
    list<Entry*> contents;

    int getSize(){
        int count = 0;
        for(Entry* e : contents){
            Directory* d = dynamic_cast<Directory*>(e);
            if( d != nullptr)
            {
               count+=d->getSize();
            }
            else if( (dynamic_cast<File*>(e)) != nullptr){
                count++;
            }
        }
    }

    Bag<int>

};


