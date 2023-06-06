#include <iostream>
#include <cmath>
using namespace std;

class Vector3D{
public:
    Vector3D(double x, double y, double z);
    double *get_values() const;
    void set_values(double x, double y, double z);
    double get_magnitude() const;
    Vector3D cross_product(Vector3D const & other) const;
    bool operator<(Vector3D const & other) const;
    double operator*(Vector3D const & other) const;
    Vector3D operator+(Vector3D const & other) const;
    Vector3D operator-(Vector3D const & other) const;

private:
    double x;
    double y;
    double z;
};

Vector3D::Vector3D(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}
void Vector3D::set_values(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}
double Vector3D::get_magnitude(){
    return sqrt(x*x + y*y +z*z);
}


#ifndef MARMOSET_TESTING
int main();
#endif
#ifndef MARMOSET_TESTING
int main()
{

return 0;
}
#endif
