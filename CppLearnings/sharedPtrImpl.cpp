// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

struct MediaAsset
{
    virtual ~MediaAsset() = default;

    friend std::ostream &operator<<(std::ostream &os, const MediaAsset &asset) {
        return os;
    }
    // make it polymorphic
};

class Song : public MediaAsset
{
public:
    wstring artist;
    wstring title;

    Song(const std::wstring& artist_, const std::wstring& title_) :
            artist{ artist_ }, title{ title_ } {}

//    friend std::ostream &operator<<(std::ostream &os, const Song &song) {
//        os << static_cast<const MediaAsset &>(song) << " artist: " << song.artist << " title: " << song.title;
//        return os;
//    }
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
            const std::wstring& date_,
            const std::wstring& location_,
            const std::wstring& subject_) :
            date{ date_ }, location{ location_ }, subject{ subject_ } {}
};


int main()
{
    // The examples go here, in order:
    //    // Example 1
    //    // Example 2
    //    // Example 3
    //    // Example 4
    //    // Example 6

// Use make_shared function when possible.
    auto sp1 = make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");

// Ok, but slightly less efficient.
// Note: Using new expression as constructor argument
// creates no named variable for other code to access.
    shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

// When initialization must be separate from declaration, e.g. class members,
// initialize with nullptr to make your programming intent explicit.
    shared_ptr<Song> sp5(nullptr);
//Equivalent to: shared_ptr<Song> sp5;
//...
    sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing");
    //cout<<sp1.use_count()<<" "<<sp2.use_count()<<" "<<sp5.use_count()<<endl;

    //Initialize with copy constructor. Increments ref count.
    auto sp3(sp2);

//Initialize via assignment. Increments ref count.
    auto sp4 = sp2;

//Initialize with nullptr. sp7 is empty.
    shared_ptr<Song> sp7(nullptr);

    cout<<"sp1: "<<sp1.use_count()<<" sp2: "<<sp2.use_count()<<" sp5: "<<sp5.use_count()
    <<" sp3: "<<sp3.use_count()<<" sp4: "<<sp4.use_count()<<" sp7 "<<sp7.use_count()<<endl;

    sp1.swap(sp2);
    cout<<" After swap \n sp1: "<<sp1.use_count()<<" sp2: "<<sp2.use_count()<<endl;

    vector<shared_ptr<Song>> v {
            make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
            make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
            make_shared<Song>(L"Thalia", L"Koi Mil gaya")
    };

    vector<shared_ptr<Song>> v2;

    remove_copy_if(v.begin() , v.end(), back_inserter(v2) , [](shared_ptr<Song>& s){
        cout<<s.use_count()<<endl;
        return s->artist.compare(L"Aretha Franklin") == 0;
    });

    for (const auto& s : v2)
    {
        wcout<< s->artist << L" : " << s->title << endl;
    }

    // Initialize two separate raw pointers.
// Note that they contain the same values.
    auto song1 = new Song(L"Village People", L"YMCA");
    auto song2 = new Song(L"Village People", L"YMCA");

    // Create two unrelated shared_ptrs.
    shared_ptr<Song> p1(song1);
    shared_ptr<Song> p2(song2);

    wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
    wcout << "p1 == p2 = " << std::boolalpha <<(p1 == p2) << endl;
    // Related shared_ptr instances are always equal.
    shared_ptr<Song> p3(p2);
    wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;
}