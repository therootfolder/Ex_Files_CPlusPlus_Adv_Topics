// takes in a double and converts into pronunciation  
#include<string>
#include<new>
#include<iostream>
#include<vector>

using namespace std;

void mynumword(const string);
vector<string> getdigits(const string ,const size_t );


int main(){
    string str;
    char n[128];
   
    cout<<"enter the number: ";
    cin.getline(n,128);
    
   mynumword(n);
    cout<<str<<endl;
    return 0;
}

void mynumword(const string  num ){
    
    size_t len= num.size();
    vector<string>digits;
    digits = getdigits(num,len);
    cout<<"the length is : "<<len<<endl;
    int comma=0;
    for(string sent:digits){
        cout<<sent<<" ";
        if(comma%2 && comma != digits.size() -1)cout<<",";// comma%2 will be 1 when comma is odd.
        ++comma;       
    }
 
    return;
    
}

vector<string> getdigits(const string numg,const size_t leng ){
    int exp = leng;
    vector<string> digits(0);// vector of length 0. will do without it tho.
    while(exp>0){
        for(char c: numg){
            switch (c){
                case '0': digits.push_back("zero");break;
                case '1': digits.push_back("one");break;
                case '2': digits.push_back("two");break;
                case '3': digits.push_back("three");break;
                case '4': digits.push_back("four");break;
                case '5': digits.push_back("five");break;
                case '6': digits.push_back("six");break;
                case '7': digits.push_back("seven");break;
                case '8': digits.push_back("eight");break;
                case '9': digits.push_back("nine");break;
            }

            switch(exp){
                case 1:digits.push_back("ones");break;
                case 2:digits.push_back("tens");break;
                case 3:digits.push_back("hundreds");break;
                case 4:digits.push_back("thousands");break;
                case 5:digits.push_back("ten-thousands");break;
                case 6:digits.push_back("lakhs");break;
                case 7:digits.push_back("ten-lakhs");break;
                case 8:digits.push_back("crores");break;
                case 9:digits.push_back("ten-crores");break;
                case 10:digits.push_back("hundred-crores");break;
              
                
            }

            --exp;
        }
    }

return digits;
}