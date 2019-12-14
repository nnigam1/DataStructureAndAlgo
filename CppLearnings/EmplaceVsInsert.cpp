#include<iostream>
#include<vector>
#include<list> // double link list
#include<forward_list> // single link list
#include<algorithm>
using namespace std;

class Pair {
public:
    int getX() const {
        return x;
    }

    void setX(int x) {
        Pair::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Pair::y = y;
    }

private:
    int y;
    int x;
public:
    Pair(int x, int y) : x(x) , y(y) {}

    friend ostream &operator<<(ostream &os, const Pair &pair) {
        os <<"[" <<pair.x <<","<< pair.y<<"]";
        return os;
    };
};

int main()
{
    // difference between emplace and insert
    vector<Pair> vec;
    list<Pair> ls;
    vec.emplace_back(3,4);

   // vec.emplace(3,4);
   vec.push_back({3,4});

   for(int i = 0 ; i <8 ; i++) {
       ls.emplace_back(i , i+1);
   }
   ls.emplace_front(8 , 9);

   for( auto itr : ls) {
       cout<<itr<<"->";
   }
   cout<<endl;
   list<Pair>::reverse_iterator  revItr = ls.rbegin();

   for_each(ls.rbegin() , ls.rend() , [ls](const Pair i) {
      cout<<i<<"->";
   });

   list<Pair> ls2;
   ls2.emplace_front(99,100);
   ls2.emplace_front(101, 102);
//
//   //ls.swap(ls2);
//   ls.merge(ls2 , [](const Pair i , const Pair j ) -> bool{
//      return i.getX() <j.getX();
//   });
//
//   cout<<endl;
//    for( auto itr : ls) {
//        cout<<itr<<"->";
//    }
    cout<<endl;

    ls.splice(ls.begin() , ls2);

    for( auto itr : ls) {
        cout<<itr<<"->";
    }


    cout<<endl;
    forward_list<Pair> fls;
    fls.emplace_front(1,2);
     auto itr = fls.emplace_after(fls.begin() , 3,4);
    fls.emplace_after(itr , 5,6 );


    for_each(fls.begin() , fls.end() ,[](const Pair i){
        cout<<i<<" ";
    });
    cout<<endl;

    vector<char> charVec = {'a','b','c'};

    sort(charVec.begin() , charVec.end());

    do {
        for_each(charVec.begin() , charVec.end() , [charVec](const char c) {
           cout<<c<<" ";
        });
        cout<<endl;
    } while( next_permutation( charVec.begin() , charVec.end()));

return 0;
}

