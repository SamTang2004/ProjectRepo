#include <iostream>

using namespace std;

int main(){

    int a;
    int b;
    int c;
    cin>>a>>b>>c;

    cout<<(a>b?(a>c?a:c):(b>c?b:c))<<endl;
    cout<<(a<b?(a<c?a:c):(b<c?b:c))<<endl;

    return 0;
}
