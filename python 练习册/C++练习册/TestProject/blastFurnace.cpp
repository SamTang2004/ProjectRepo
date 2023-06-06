#include <iostream>
using namespace std;
int main();
int f(int currWater, int runReq);

int main(){
    cout<<f(102000,10000);
}

int f(int currWater, int runReq){

    int n = currWater / runReq;

    cout<<"number of operations: "<<n<<endl;

    return n*runReq + runReq - currWater;

}
