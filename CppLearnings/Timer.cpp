#include<chrono>
#include<iostream>

class Timer {
private :
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double , std::ratio<1,1> >;

    std::chrono::time_point<clock_t> m_beg;
public:

    Timer() : m_beg(clock_t::now()) {};

    void reset()
    {
        m_beg = clock_t::now();
    }

    double timeElapsedInSeconds()
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }

};

int main()
{
    Timer timerObj;
    std::cout<<"I will get success"<<std::endl;
    std::cout<<"Time elapsed is:"<<timerObj.timeElapsedInSeconds();
    return 0;
}

