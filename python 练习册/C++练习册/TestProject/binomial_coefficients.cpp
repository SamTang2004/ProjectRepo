#include <iostream>

long factorial(int from,int to){
    long re = 1;
    for (int i =from;i<=to;i++){
        re *= i;
    }
    return re;
}
long nCk(int n, int k){

    if (n<k || k<0){
        return -1000;
    }

    return factorial(1,n) / (factorial(1,k) * factorial(1,n-k));
}
int main(){
    int n;
    int k;
    std::cout<<"Binomial Coefficients Calculator"<<std::endl;
    std::cout<<"Enter the value for n: ";
    std::cin>>n;
    std::cout<<"Enter the value for k: ";
    std::cin>>k;
    long res = nCk(n,k);
    if (res == -1000){
        std::cout<<"Cannot calculate nCk because condition n >= k >= 0 was not met.";
        return 0;
    }
    std::cout<<"The value of nCk is "<<nCk(n,k)<<". "<<std::endl;
    return 0;
}
