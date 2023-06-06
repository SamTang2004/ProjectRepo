#include <iostream>
using namespace std;

int main();
unsigned int f(unsigned int num);
void changeMachine(unsigned int changeAmount);
int main(){
    //cout<<f(2147483648*2-1);
    cout<<f(29)<<endl;

    changeMachine(f(29));
    return 0;
}


unsigned int f(unsigned int num){
    long long n = num/5;
    // either num/5*5(which is the largest 5's multiple under and equal to n) or
    // num/5*5+5 (which is the smallest 5's multiple above n) will meet the condition
    // since abs does not contain a definition for unsigned int we have to convert num to long or long long first.
    // we must use long long for n because n * 5 has to be long long

    return abs(n*5-(long long)num) < abs(n*5+5-(long long)num) ? n*5 : n*5+5;
}

// here you can start changemachine with an amount of money in dollars
void changeMachine(double change){
    changeMachine(change*100);
}

void changeMachine(unsigned int changeAmount){
    if (changeAmount == 0){
        return;
    }

    if (changeAmount >= 25){
        cout<<25<<" ";
        changeMachine(changeAmount - 25);
        return;
    }
    if (changeAmount >= 10){
        cout<<10<<" ";
        changeMachine(changeAmount - 10);
        return;
    }
    if (changeAmount >= 5){
        cout<<5<<" ";
        changeMachine(changeAmount - 5);
        return;
    }
    return;
}
