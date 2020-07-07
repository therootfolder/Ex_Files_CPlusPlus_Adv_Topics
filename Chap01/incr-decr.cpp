// incr-decr.cpp by Bill Weinman <http://bw.org/>
// version of 2018-11-10
#include <iostream>
using namespace std;

class num {
    int value = 0;
public:
    num( int x = 0 ) : value(x) {}
    int getvalue() const { return value; }
    void setvalue( int x ) { value = x; }
    num & operator ++ ();
    num operator ++ (int);// the int is just a dummy value to tell the compiler to 
    // differentiate between a pre-fix increment and a post-fix increment.
    // and this dummy type is always int.

    // infact my class is a num but it still says int.
    num & operator -- ();
    num operator -- (int);
};


// pre-increment
num & num::operator ++ () {
    cout << "pre-increment: ";
    value += 1;
    return *this;
}

// post-increment
num num::operator ++ (int) {// note even here it still says int and takes no name 
    cout << "post-increment: ";
    num temp = *this;// this is the pointer to the current object which is of class num and property value. this will hold the starting address thats why it works i think.
    value += 1;
    return temp;
}

// pre-decrement
num & num::operator -- () {
    cout << "pre-decrement: ";
    value -= 1;
    return *this;
}

// post-decrement
num num::operator -- (int) {
    cout << "post-decrement: ";
    num temp = *this;
    value -= 1;
    return temp;
}

ostream & operator << (ostream & o, const num & n) {// overloading the << operator. very important.
    return o << (n.getvalue());
}

int main()
{
    num n(42);
    cout << "value is " << n << endl;
    cout << "value is " << ++n << endl;
    cout<<"value is "<< n++<< endl;
    cout << "value is " << n << endl;
    return 0;
}
