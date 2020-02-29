#include<iostream>
#include<queue>
#include<chrono>
#include<map>
using namespace std;

const int MaxAllowedReq = 5;
using timestamp = chrono::steady_clock::time_point;

class Customer
{
public:
    int custId;
    map< timestamp , int> mp;
    Customer()
    {
        chrono::steady_clock::time_point now = chrono::steady_clock::now();
        mp[now] = MaxAllowedReq;
    }
};



bool canProcess( Customer* cust)
{
    timestamp requestTime = chrono::steady_clock::now();
    auto itr = cust->mp.begin();
    auto millSeconds = chrono::duration_cast<chrono::milliseconds>(requestTime - itr->first );
    if( millSeconds.count() > 1000 )
    {
        cust->mp.erase(itr);
        cust->mp.insert({requestTime , MaxAllowedReq});
    }
    else
    {
        if( itr->second <= 0)
            return false;
        else{
            int count = itr->second;
            cust->mp.erase(itr);
            count = count -1;
            cust->mp.insert({requestTime , count});
        }
    }
    return true;
}

int main()
{
    map<int , Customer*> customerRateLimit;
    customerRateLimit.insert({1 , new Customer()});
    customerRateLimit.insert({2, new Customer()});
    int T;
    while(1)
    {
        if( canProcess(customerRateLimit[1])) {
            cout << " Processing" << endl;
        }
        else {
            cout << "Can't Process for 1" << endl;
            break;
        }
    }
    return 0;
}