#include <iostream>
using namespace std;
#include <bitset>

unsigned int mb(unsigned int n){

    return (n/256*256)%(((unsigned int)1)<<24);

}

int main(){

cout<<(bitset<32>(mb(0b10010101010111110100100110101010)));


}
