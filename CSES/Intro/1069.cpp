#include <iostream>
using namespace std;
 
int main(){
string s;
cin>> s;
int n= s.length(), max=1, c= 1;
for(int i=0 ; i<= n-2; i++) {
    if(s[i] == s[i+1]) c++;
    else c= 1;
    max = (max > c)? max : c;
  }
cout<< max ;
return 0;
}
