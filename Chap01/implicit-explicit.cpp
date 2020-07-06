// implicit-explicit.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-08
#include <cstdio>
using namespace std;

class c1 {
    int _value = 0;
    c1();
public:
    c1 (const int & value) : _value(value) {}
    // now if you dont want implicit conversion
    //  to happen for a paritcular instantiation
    // of an object, you can make it explicit 
    // by using the keyword explicit.
    explicit c1 (const int & value) : _value(value) {}
    // the above line will give errors from the compiler
    void setvalue( const int & value ) { _value = value; }
    int getvalue() const { return _value; }
};

void func(const c1 & o) {
    printf("value is %d\n", o.getvalue());
}

int main() {
    c1 bat(34);// this works
    //c1 cat; this doesnt work since the default constructor is made private.
     
    printf("value is %d\n",bat.getvalue());
    c1 o = 'x';// this will automatically get converted to the int type
    printf("value is %d\n", o.getvalue());
    func('x');
    return 0;
}

