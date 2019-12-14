#include<iostream>
#include<string>
#include<memory>
#include<chrono>
using namespace std;

class Timer {
    using clock_t = chrono::high_resolution_clock;
    using second_t = chrono::duration< double ,ratio<1,1000>>;
public:
    chrono::time_point<clock_t> m_beg;

    Timer() : m_beg(clock_t::now()) {}

    double timeElapsedInSeconds()
    {
        return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }

    void resetTime()
    {
        m_beg = clock_t::now();
    }
};

class Tuple {
public:
    Tuple(int x, const string &str, float y) : x(x), str(str), y(y) {}

    int getX() const {
        return x;
    }

    void setX(int x) {
        Tuple::x = x;
    }

    const string &getStr() const {
        return str;
    }

    void setStr(const string &str) {
        Tuple::str = str;
    }

    float getY() const {
        return y;
    }

    void setY(float y) {
        Tuple::y = y;
    }

private:
    string str;
    float y;
    int x;
};

template<typename T , typename... Types>
unique_ptr<T> myMakeUniqueMove(Types&&... args)
{
    return unique_ptr<T>( new T(forward<Types>(args)...));
};

template<typename T , typename... Types>
unique_ptr<T> myMakeUnique(Types... args)
{
    return unique_ptr<T>( new T(args...));
};


int main()
{

    Timer timerObj2;
    unique_ptr<Tuple> myPtr3 = myMakeUnique<Tuple>( 28, "hello" , 9.8);
    cout<<timerObj2.timeElapsedInSeconds()<<endl;

    Timer timerObj;
    unique_ptr<Tuple> myPtr2 = myMakeUniqueMove<Tuple>( 23, "hello" , 9.8);
    cout<<timerObj.timeElapsedInSeconds()<<endl;


    return 0;
}
