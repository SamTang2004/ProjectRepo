#include <iostream>

using namespace std;

class dlist{
public:
    dlist(unsigned int cap, double def);
    unsigned int capacity();
    double getAtIndex(int index);
    void setAtIndex(int index, double val);
    ~dlist();

private:
    double* arr;
    double def;
    unsigned int cap;
};

dlist::dlist(unsigned int cap, double def = 0.0){
    arr = new double[cap]{def};
    this->def = def;
}

unsigned int dlist::capacity(){
    return cap;
}

double dlist::getAtIndex(int index){
    return index < cap ? arr[index] : def;
}

void dlist::setAtIndex(int index,double val){
    if (index < 0){
        throw std::domain_error("invalid index");
        return;
    }
    if (index <  cap){
        arr[index] = val;
        return;
    }

    double* newList = new double[index]{def};



}



