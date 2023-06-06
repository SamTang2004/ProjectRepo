#include <iostream>

unsigned int gcd( unsigned int m, unsigned int n ) {
    if (m < n){
        temp = m;
        m = n;
        n = temp;


    }


while ( (m % n) != 0 ) {
unsigned int r{m % n};
m = n;
n = r;
}
return n;
}

