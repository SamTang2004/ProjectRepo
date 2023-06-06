#include <iostream>

int main();
using namespace std;
class A{
public:
    virtual void a();
};

class B: public A{
public:
    void b();
    void a() override;
};

class C: public B{
public:
    void c();
    void a() override;
};
class D{

public:
    int n;
    int m;
    int k;
    int getVal(){
    return n+m+k;
    }
private:

};
void A::a(){
    cout<<"A"<<endl;
}
void B::b(){
    cout<<"B"<<endl;
}
void B::a(){
    cout<<"BA"<<endl;
}
void C::c(){
    cout<<"C"<<endl;
}
void C::a(){
    B::a();
    cout<<"CA"<<endl;
}

int main(){
    B* cp = new C{};
    cp->a();
    cp->b();
    B var{};
    A var2{};
    var2 = var;
// this step discards all of the new stuff in that B object.
    var2.a();
    D* d = new D{-1,1,2};
    cout<<d->getVal();
return 0;
}
