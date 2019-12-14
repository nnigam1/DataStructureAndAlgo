#include<iostream>
using namespace std;

float power(float a , int b)
{
    float temp = 0;
    if( b == 0)
        return 1;

    temp = power(a, b / 2);
    if( b % 2 == 0) {
        return temp * temp;
    }
    else{
        if( b > 0 )
        {
            return a * temp * temp;
        } else
        {
            return (temp * temp)/a;
        }

    }

}
