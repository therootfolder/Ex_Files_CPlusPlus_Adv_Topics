// rational2.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-03 for CppAdv
#include <cstdio>
#include <iostream>
#include<string>
using namespace std;

class Rational {
    int _n = 0;
    int _d = 1;
public:
    Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
    Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};    // copy constructor
    ~Rational ();
    int numerator() const { return _n; };
    int denominator() const { return _d; };
    Rational & operator = ( const Rational & );
    // conversion operator to string
    operator std::string() const;// what this is essentially doing is (std::string)b work.
};

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}
//conversion operator to a string.
Rational::operator std::string() const{
       if(_d == 1) return std::to_string(_n);
       else return std::to_string(_n) + "/" + std::to_string(_d);// here the plus means
    //    the concatenation operator.and to_string() will make the object into a stream of characters.

}
//non member operator overloads here below:
Rational operator + ( const Rational & lhs, const Rational & rhs ) {
    return Rational((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator - ( const Rational & lhs, const Rational & rhs ) {
    return Rational((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator()), lhs.denominator() * rhs.denominator());
}

Rational operator * ( const Rational & lhs, const Rational & rhs ) {
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

Rational operator / ( const Rational & lhs, const Rational & rhs ) {
    return Rational(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

Rational::~Rational() {
    _n = 0; _d = 1;
}

// for std::cout
// this code changes after we did the conversion to string operator.
std::ostream & operator << (std::ostream & o, const Rational & r) {
    // BEFORE
    // if(r.denominator() == 1) return o << r.numerator();
    // else return o << r.numerator() << '/' << r.denominator();
    // NOW
    return o<< std::string(r);//just convert the rhs to a string that we implemented earlier.
    // wow
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
    Rational & e = d;    // reference
    d = e;                // assignment to self!
    cout << "e is: " << e << endl;
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    cout<<"demo of non-member operator overload"<<endl;
    cout << 14 << " + " << b << " = " << 14 + b << endl;

    string s = "Rational value is: ";
    s += b;// it says no viable overloaded += operator. this was before we implemented the conversion operator to string
    // so how to achieve this? use a conversion operator.
    cout<< s<<endl;// wow now it works like a charm. brilliant.
    // now the other benefit of this is we can simplify the code for our overloaded << operator.
    return 0;
}
