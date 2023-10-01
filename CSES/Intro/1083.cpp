#include <iostream>
typedef long long ll;
using namespace std;
int main(){
    // freopen("test_input.txt","r",stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin>> n;
    ll tSum= ll( ll(n)*ll(n+1)/2 );
    // ll Sum= 0;
    for(int i=0; i<= n-2; i++){
      int j;
      cin>> j;
      tSum-= j;
    }
    cout<< tSum;
  return 0;
}
