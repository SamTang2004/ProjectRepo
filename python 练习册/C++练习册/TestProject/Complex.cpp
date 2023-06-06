#include <iostream>

class Complex{
private:
    double real;
    double im;
public:
    Complex(double real, double im);
    void add_value(double add_real, double add_imag);
    void add_value(Complex add_complex);
    void get_value(double &real_val, double &imag_val);
};

Complex::Complex(double real, double im){
    this->real = real;
    this->im = im;
}
void Complex::add_value(double add_real, double add_imag){
    real += add_real;
    im += add_imag;
}
void Complex::add_value(Complex add_complex){
    real += add_complex.real;
    im += add_complex.im;
}
void Complex::get_value(double &real_val, double &imag_val){
   real_val = real;
   imag_val = im;

}

#include <iostream>
#ifndef MARMOSET_TESTING
int main();
#endif
#ifndef MARMOSET_TESTING
int main()
{
Complex starting_num{4.0,5.2};
Complex add_num{3.4,5.6};
double real_value{0.0};
double imaginary_value{0.0};
starting_num.get_value(real_value,imaginary_value);
std::cout << "real: " << real_value <<std::endl;
std::cout << "imaginary: " << imaginary_value <<std::endl;
starting_num.add_value(2.6,3.0);
starting_num.get_value(real_value,imaginary_value);
std::cout << "real: " << real_value <<std::endl;
std::cout << "imaginary: " << imaginary_value <<std::endl;
starting_num.add_value(add_num);
starting_num.get_value(real_value,imaginary_value);
std::cout << "real: " << real_value <<std::endl;
std::cout << "imaginary: " << imaginary_value <<std::endl;
return 0;
}
#endif
