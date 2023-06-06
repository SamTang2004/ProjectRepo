#include <iostream>
#include <vector>
bool isPrime(int k);

int main(){
    int a;
    int b;
    std::cout<<"enter a: ";
    std::cin>>a;
    std::cout<<"enter b: ";
    std::cin>>b;
    std::vector<int> arr;
    for(int i =a;i<=b;i++){
        if (isPrime(i)){
            arr.push_back(i);
        }
    }
    if (arr.size()==0){
        std::cout<<"No primes in range."<<std::endl;
        return 0;
    }else{
        std::cout<<"Primes in range: ";
        for (int i = 0; i < arr.size();i++){
            std::cout<<arr.at(i)<<" ";
        }
    std::cout<<std::endl;

    }

    return 0;
}
bool isPrime(int k){
    for (int i =2;i<k;i++){
        if (k%i==0){
            return false;
        }
    }
    return true;
}
