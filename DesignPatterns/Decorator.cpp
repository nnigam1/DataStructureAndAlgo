#include<iostream>
using namespace std;

class BasePizza
{
public:
    virtual int getCost() = 0;
};

class PanPizza : public BasePizza
{
public:
    int getCost() override {
        return 20;
    }
};

class ThinCrustPizza : public BasePizza
{
public:
    int getCost() override {
        return 30;
    }
};

class ToppingsDecor : public BasePizza
{
    virtual int getCost() = 0;
};

class CheeseBurst : public ToppingsDecor
{
    BasePizza* bp;
public:
    CheeseBurst(BasePizza* b) : bp(b){
    }
    int getCost() override {
        if( bp != NULL)
        {
            return bp->getCost() + 50;
        }
    }
};

class VegLoaded : public ToppingsDecor
{
    BasePizza* bp;
public:
    VegLoaded(BasePizza* b) : bp(b){
    }
    int getCost() override {
        if( bp != NULL)
        {
            return bp->getCost() + 30;
        }
    }
};

int main()
{
    PanPizza* pp = new PanPizza();
    CheeseBurst* cb = new CheeseBurst(pp);
    cout<<cb->getCost()<<endl;

    VegLoaded* vl = new VegLoaded(pp);
    cout<<vl->getCost()<<endl;
}


