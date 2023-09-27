#include "bits/stdc++.h"
 
using namespace std;
using ll = long long;
 
const int MAX = 1e5 + 2;
const ll _MOD = 1e9 + 7;
 
ll b_exp(ll a, ll b, ll MOD){
	ll res = 1;
	a %= MOD;
	while (b > 0){
		if (b&1) res = ((res % MOD * a % MOD) % MOD);
		b /= 2;
		a = ((a % MOD * a % MOD) % MOD);
	}
	return res;
}
 
void solve(){
	ll a, b, c;
	cin >> a >> b >> c;
    ll y = b_exp(b, c, _MOD - 1);
    ll res = b_exp(a, y, _MOD);
    cout << res << "\n";
}
 
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
    	solve();
    }  
    
    return 0;
}
