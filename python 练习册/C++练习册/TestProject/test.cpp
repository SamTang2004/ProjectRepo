#include <iostream>
using namespace std;

class A{
public:
    A(){

    }
    A& ret(){
        return *this;
    }

};

void f(int& in){
    cout<<in;
}

int main() {

    int* arr = new int[1]{0};
    int* ptr = &arr[0];
    cout<<*ptr;
    cout<<endl;


    return 0;
}
//stack
//b
//b*

//heap
//7

