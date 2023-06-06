#include <iostream>
#include <cmath>

using namespace std;
#ifndef MARMOSET_TESTING
int main();
double find_zero(double initValue, double stepSize);
double fx(double x);
#endif
#ifndef MARMOSET_TESTING
int main() {
    cout<<find_zero(65.0,-0.5);
    return 0; }
#endif MARMOSET_TESTING

double find_zero(double initValue, double stepSize){
    double curFx;
    double prevFx;
    for (int i =0;i<100;i++){
        curFx = fx(initValue);
        prevFx = fx(initValue - stepSize);
        if (curFx*prevFx < 0){
            stepSize /= -10;
        }
        initValue += stepSize;
    }
    return initValue;
}
double fx(double x){
    return std::cos(std::sqrt(x));
}
