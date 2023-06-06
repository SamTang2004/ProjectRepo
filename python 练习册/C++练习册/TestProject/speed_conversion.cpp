#include <iostream>

int main(){
    double mph = 0;
    std::cout<<"Enter the speed in miles per hour: ";
    std::cin>>mph;
    std::cout<<std::endl;
    double kph = mph *5280/3.28084/1000;
    double ftps = mph *5280/60/60;
    double mps = kph/3.6;
    double fpfn = kph/201.168*1000*14*24;

    std::cout<<"The speed is ";
    std::cout<<mph;
    std::cout<<" miles per hour."<<std::endl;
    std::cout<<"The speed is ";
    std::cout<<ftps;
    std::cout<<" feet per second."<<std::endl;
    std::cout<<"The speed is ";
    std::cout<<mps;
    std::cout<<" meters per second."<<std::endl;
    std::cout<<"The speed is ";
    std::cout<<kph;
    std::cout<<" kilometers per hour."<<std::endl;
    std::cout<<"The speed is ";
    std::cout<<fpfn;
    std::cout<<" furlongs per fortnight."<<std::endl;

    return 0;

}
