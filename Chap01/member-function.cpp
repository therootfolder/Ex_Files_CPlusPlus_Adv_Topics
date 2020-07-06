// member-function.cpp by Bill Weinman <http://bw.org/>
// updated bw 2018-10-03
#include <cstdio>
using namespace std;

class A {
    int _value = 0;
public:
    void setv ( const int a ) { _value = a;}
    int getv () const { puts("const getv");return _value; }// i can have two function of 
    // the same name here one of them const qualified and one of them not.
    int getv() {puts("mutable getv");return _value +10;}
};

// void A::setv ( const int a ) { _value = a; };
//     int A::getv()  const{ return _value; };
int main() {
    A a;
    a.setv(42);
    printf("a is %d\n", a.getv());// this will print 52

    const A b = a;
    printf("b is %d\n",b.getv());//this will print 42
    return 0;


}
