#include <iostream>
typedef long long ll;
using namespace std;
int main(){
    // freopen("test_input.txt","r",stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin>> n;
    if(n>=4){
      for(int i=2; i<= n; i+=2)
      cout<< i<< " ";
      for(int i=1; (i<=n && i&1) || (i<= n-1 && !i&1); i+=2)
        cout<< i<< " ";
    }
    else{
      if(n == 1) cout<< n;
      else cout<<"NO SOLUTION";
    }
  return 0;
}
