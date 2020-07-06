// data.cpp by Bill Weinman <http://bw.org/>
// updated bw 2018-11-08
#include <cstdio>
using namespace std;

struct A {//these members are public by default
    int ia;
    const char * sb = "";
    int ic;
};
class B{// these members are private by default
       int ia;
    const char * sb = "";
    int ic;
};

class C{
        int ia;// this is private
public:
const char * sb = "";
    int ic;
};
int main() {
    A a;
    a.ia = 1;
    a.sb = "two";
    a.ic = 3;
    printf("ia is %d, sb is %s, ic is %d\n", a.ia, a.sb, a.ic);
    
    return 0;
}
