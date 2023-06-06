#include <iostream>
#include <cmath>
double computeVal(double a, double b, double c, double d,double x);
double binsearch(double a, double b, double c, double d, double left, double right);
int main();


int main(){
    double a;
    double b;
    double c;
    double d;
    double left;
    double right;
    std::string cont = "Y";
    do{

        std::cout<<"Enter coefficients (A, B, C, and D):";
        std::cin>>a>>b>>c>>d;
        std::cout<<"Enter the lower and upper bound of the search interval:";
        std::cin>>left>>right;
        std::cout<<"The root found was x = "<<binsearch(a,b,c,d,left,right)<<std::endl;
        std::cout<<"Do you wish to find another root (Y/N)?";
        std::cin>>cont;

    }while(cont=="Y" || cont == "y");

    std::cout<<"Program terminated.";
    return 0;
}

double binsearch(double a, double b, double c, double d, double left, double right){
    double mid = (right+left)/2.0;

    double midval = computeVal(a,b,c,d,mid);
    if (fabs(midval)<=0.0001){
        return mid;
    }
    double p = computeVal(a,b,c,d,left);
    double q = computeVal(a,b,c,d,right);
    if (midval/p < 0){
        return binsearch(a,b,c,d,left,mid);
    }
    if (midval/q <0){
        return binsearch(a,b,c,d,mid,right);
    }
    return -2147483647;
}
double computeVal(double a, double b, double c, double d, double x){
    return a*x*x*x + b*x*x + c*x + d;
}
