#include <iostream>
#include<chrono>
#include<deque>
#include<chrono>
using namespace std;

const int MaxRequestAllowed = 10;
chrono::time_point<std::chrono::system_clock> prevTs = chrono::system_clock::now();

class RateLimitObject
{
public:
    int custId;
    chrono::time_point<std::chrono::system_clock> timestamp; // time of the request.
    int count;
};

// singelton
class RateLimiter {
public:
    deque<RequestObject*> q;

    static RateLimiter& getinstance()
    {
       static RateLimiter rate;
       return rate;
    }
};

void processRequest(int req)
{
    cout<<req<<endl;
}


bool canProcess(RateLimiter& rt ,  int custId)
{
    RequestObject* req = rt.q.front();
    if(req->custId == custId  )
    {
        std::chrono::duration<double> elapsed_seconds = req->timestamp - prevTs;
        if(  elapsed_seconds < second ) {
            prevTs = req->timestamp;
            count++;
        }
        if( req->count > MaxRequestAllowed)
            return false;
    }
    return true;
}

// Test Cases:


bool Prcoessthis(int custId)
{
    RateLimiter rt = RateLimiter::getinstance();
    canProcess(custId , rt );
}


int main() {


}


// Request are in queue
// processRequest which is something like time bound
// so that we have to find out no. of times processRequest gets called in 1 second
// if that num > maxLimit then we return false
//sliding window
// how many request processed in 1sec.
//    deque<RequestObject*> dq;
//    RequestObject* rq = dq.front();
//    if(
// for this second reuq> max
// reuqest all already there;