// class.cpp by Bill Weinman <http://bw.org/>
// updated bw 2018-10-03
#include <cstdio>
using namespace std;

// a very simple class
class c1 {
    int i = 0;
public:
    void setvalue( const int & value ) { i = value; }
    int getvalue() const ;
    int getvalue1() const;
};

    int c1::getvalue() const { 
        printf("getvalue: this is %0p\n",this);//%p will give the hexadecimal value of the pointer this.
        return i;
         }
int c1::getvalue1() const{
    printf("getvalue1: \n");
    return (this->i)+1;
}

int main() {
    const int i = 47;
    c1 o1;// this is actually the implicit default constructor. wow just amazing.
    o1.setvalue(i);
    printf("address of o1 is %p\n",&o1);// will print an hexadecimal value of the address of o1
    printf("value is %d\n", o1.getvalue());//prints 47
    c1 o2 = o1;// this is actually the implicit copy constructor. just wow.
   printf("value is %d\n", o2.getvalue1());// prints 48
    return 0;
}
