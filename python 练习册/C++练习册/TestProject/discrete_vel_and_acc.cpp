#include <iostream>

void output_velocity_and_acceleration(double position_measurements[],std::size_t qty_measurements);

#ifndef MARMOSET_TESTING
int main();
#endif
#ifndef MARMOSET_TESTING
int main()
{

    double pos[1]{-1.3};
    output_velocity_and_acceleration(pos,1);

    return 0;
}
#endif

void output_velocity_and_acceleration(double position_measurements[],std::size_t qty_measurements){
    if (qty_measurements<2){

        std::cout<<"Insufficient measurements for velocity calculation."<<std::endl;
        std::cout<<"Insufficient measurements for acceleration calculation."<<std::endl;

        return;
    }


    double vels[qty_measurements -1]{0};
    std::cout<<"Velocity calculations [m/s]:"<<std::endl;
    for (int i{0};i<qty_measurements-1;i++){
        vels[i] = position_measurements[i+1]-position_measurements[i];
        std::cout<<vels[i]<<" ";
    }


    std::cout<<std::endl;
        if (qty_measurements<3){
        std::cout<<"Insufficient measurements for acceleration calculation."<<std::endl;
        return;
    }
    std::cout<<"Acceleration calculations [m/s^2]:"<<std::endl;
    for(int i{0};i<qty_measurements-2;i++){
        std::cout<<(vels[i+1]-vels[i])<<" ";
    }
    std::cout<<std::endl;
}

