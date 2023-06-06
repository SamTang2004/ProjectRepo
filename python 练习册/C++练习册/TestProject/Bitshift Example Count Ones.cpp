#include <iostream>
#include <bitset>
using namespace std;
int main();
int main() {
    int num = -5;
    int c = 0;
    int mask = 1;
    /*
    for(int i{0};i<32;i#++){
        if (num&mask){
            c++;
        }
        mask <<=1;
    }
    int a = -1;
    int b = 0b1;

    cout<<(a&b)<<endl;
    cout<<(a>>1)<<endl;
    */

    while (num != 0){
        if (num&mask){
            c++;
        }
        num >>=1;
        cout<<c<<endl;
        cout << std::bitset<32>(num) <<endl;
    }

    cout<<c<<endl;
}

