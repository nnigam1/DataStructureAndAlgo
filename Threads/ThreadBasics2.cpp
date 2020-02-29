#include<iostream>
#include<thread>
using namespace std;

class Fctor{
public:
    void operator()(){
        for(int i = 0 ; i> -100 ; i--){
            cout<<"from t1 : "<<i<<endl;
        }
    }
};

int main(){
    Fctor fct;
    thread t1((Fctor()));

    try {
        for (int i = 0; i < 100; i++) {
            cout << "from main : " << i << endl;
        }
    } catch(...){
        t1.join();
       throw;
    }

    t1.join();

    return 0;
}

