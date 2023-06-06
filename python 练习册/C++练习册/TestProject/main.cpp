#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// declarations
int main();
double ceil(double x, double top);


// actual code
int main()
{
    cout<<ceil(-20,15);
    return 0;
}


double ceil(double x, double top){

    return abs(x)>=top ? (x > top ? top : -top) : x;

}
