#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt", "w", stdout);
    unsigned long long n;
    cin>> n;
    while(n !=1){
      cout<< n<< " ";
      if(n&1) n= n*3 +1;
      else n/=2;
    }
    cout<< n<< " ";
  return 0;
