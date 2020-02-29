#include<iostream>
#include<vector>
#include<list>
#include<chrono>
using namespace std;

const int maxElement = 10000;

int main()
{
    using clock_t = chrono::steady_clock;
    using time = chrono::milliseconds ;
    vector<int> v;

    clock_t::time_point start = clock_t::now();
    for(int i = 0 ; i < maxElement ; i++) {
        v.push_back(i+1);
    }
    clock_t::time_point end = clock_t::now();
    cout<<"Time elapsed for vector insertion :"<< chrono::duration_cast<time>(end - start).count()<<endl;
    cout<<"vector size : "<<v.size()<<endl;
    list<int> l;
    clock_t::time_point start1 = clock_t::now();
    for(int i = 0 ; i < maxElement ; i++ )
    {
        l.push_back(i+1);
    }
    clock_t::time_point end1 = clock_t::now();
    cout<<"Time elapsed for list insertion:"<< chrono::duration_cast<time>(end1 - start1).count()<<endl;
    cout<<"list size : "<<l.size()<<endl;
    int n = v.size();
    clock_t::time_point start2 = clock_t::now();
    for(auto itr : v) {
        v.erase(v.begin());
    }
    clock_t::time_point end2 = clock_t::now();
    cout<<"Time elapsed for vector deletion:"<< chrono::duration_cast<time>(end2 - start2).count()<<endl;
    cout<<v.size()<<" ";
    for( auto itr : v)
    {
        cout<<itr<<" ";
    }
    cout<<endl;
    clock_t::time_point start3 = clock_t::now();
    for(auto itr : l) {
        l.erase(l.begin());
    }
    clock_t::time_point end3 = clock_t::now();
    cout<<"Time elapsed for list deletion:"<< chrono::duration_cast<time>(end3 - start3).count()<<endl;
    cout<<l.size()<<" ";
    return 0;
}

