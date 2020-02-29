// Token-Bucket Algorithm

#include<iostream>
#include<chrono>
#include<algorithm>
using namespace std;

class RateLimiter
{
    int maxBucketSize;
    double refillRate;
    chrono::steady_clock::time_point lastRefillTs;
    int currentBucketSize;
public:
    RateLimiter()
    {
        maxBucketSize = 10;
        refillRate = 0.01;
        lastRefillTs = chrono::steady_clock::now();
    }

    void refill()
    {
        chrono::steady_clock::time_point now = chrono::steady_clock::now();
        auto milliseconds = chrono::duration_cast<chrono::milliseconds>(now - lastRefillTs);
        double refillTokens = milliseconds.count() * refillRate;
        currentBucketSize = currentBucketSize + refillTokens;
        currentBucketSize = min(currentBucketSize , maxBucketSize);
        lastRefillTs = now;
    }

    bool allowRequest(int tokens)
    {
        refill();
        if( currentBucketSize > tokens) {
            currentBucketSize = currentBucketSize - tokens;
            return true;
        }
        return false;
    }
};







