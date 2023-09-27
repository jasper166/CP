#include <iostream>
typedef long long ll;
using namespace std;
int main(){
    // freopen("test_input.txt","r",stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin>> n;
    ll k=0;
    int f_num, o_num, d;
    for(int i=1; i<= n; i++){
      d= 0;
      if(i>1){
        cin>> o_num;
        if(f_num > o_num){
          d= f_num - o_num;
          k+= (ll) d;
        }
        f_num = o_num + d;
      }
      else{
        cin>> f_num;
      }
    }
    cout<< k;
  return 0;
}
