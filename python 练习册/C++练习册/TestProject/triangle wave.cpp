#include <iostream>
using namespace std;
double triangleWave(double x);

int main();
int main(){


    cout<<triangleWave(-23);
    return 0;
}

double triangleWave(double x){


    if (x>0){
        while (x>4){
            x-=4;
        }
    }else{
        while(x<0){
            x+=4;
        }
    }
    return x<2?-x+1:x-3;
}
