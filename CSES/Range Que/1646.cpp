/*  
 *  author: Hiu 
 *  Handle: at0miccat
*/
#include "bits/stdc++.h"
using namespace std;
 
// const int MOD = (int) 1e9 + 7;
// const long long MAX = (long long) 1e18;
const int MAX = (int) 1e7+2;
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    int arr[n];
    long long prefix[n+2];
    for(int &i : arr) {
        cin >> i;
    }    
    prefix[0] = arr[0];
    for(int i = 1; i <= n-1; i++) prefix[i] = prefix[i-1] + arr[i];
    // for(int i : prefix) cout << i << " ";
    while(q--){
        int a, b;
        cin >> a >> b;
        // cout << a << b;
        if(a >= 2) cout << prefix[b-1] - prefix[a-2] << "\n";
        else cout << prefix[b-1] << "\n";
    }
 
    return 0;
}
