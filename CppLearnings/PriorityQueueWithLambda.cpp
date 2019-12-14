#include<iostream>
#include<queue>
#include<vector>
using namespace std;

enum class Color: bool {RED , GREEN };

void SamplePriorityQueueWithLamda()
{
    // using lambda to compare elements.
    auto compare = [](int lhs, int rhs)
    {
        return lhs > rhs;
    };

    std::priority_queue<int, std::vector<int>, decltype(compare)> q(compare);

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);

    cout<<q.top();
    Color c = Color::RED;
    if(c == 1)
    {
        cout<<"hello";
    }
}

int main()
{
    SamplePriorityQueueWithLamda();
}