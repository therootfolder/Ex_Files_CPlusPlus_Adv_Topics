// rational.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-03 for CppAdv
#include <cstdio>
#include <iostream>
using namespace std;

class Rational {
    int _n = 0;
    int _d = 1;
public:
    Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};// this is very useful to implicitly convert an int to this object. when it takes in a number ,
    //it becomes the numberator and the denominator becomes 1
    Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};    // copy constructor
    ~Rational ();
    int numerator() const { return _n; };
    int denominator() const { return _d; };
    Rational & operator = ( const Rational & );
    Rational operator + ( const Rational & ) const;
    Rational operator - ( const Rational & ) const;
    Rational operator * ( const Rational & ) const;
    void operator / ( const Rational & ) const;// i changed this to void it was Rational originally
    // i had to check something
};

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator - ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator * ( const Rational & rhs ) const {
    return Rational(_n * rhs._n, _d * rhs._d);
}

void Rational::operator / ( const Rational & rhs ) const {
    // return Rational(_n * rhs._d, _d * rhs._n);
    printf("%d / %d\n",_n,_d);// prints the objects nr and dr
}

Rational::~Rational() {
    _n = 0; _d = 1;
}

// for std::cout
std::ostream & operator << (std::ostream & o, const Rational & r) {//ostream object
    if(r.denominator() == 1) return o << r.numerator();
    else return o << r.numerator() << '/' << r.denominator();
}

int main() {
    
    Rational a = 7;        // 7/1
    cout << "a is: " << a << endl;
    Rational b(5, 3);    // 5/3
    cout << "b is: " << b << endl;
    Rational c = b;        // copy constructor
    cout << "c is: " << c << endl;
    Rational d;            // default constructor
    cout << "d is: " << d << endl;
    d = c;                // assignment operator
    cout << "d is: " << d << endl;
    Rational & e = d;    // reference// so no object is created since it is reference
    d = e;                // assignment to self!
    cout << "e is: " << e << endl;
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    // cout << a << " / " << b << " = " << a / b << endl;
    a/b;



    // cout<<14+b<<endl; you cant do this with member operator overload. only works with non-member operator overload of +

    return 0;
}
