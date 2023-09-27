/**    
* LANG: C++ 
* author: atom 
* created: 22.05.2022 17:44:42
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

string s;
int q, l, r, n;
ll f1[MAX], f2[MAX], base = 31, myP[MAX];

ll get_hash_1(int x, int y){
	return (f1[y] - f1[x - 1] * myP[y - x + 1] % MOD + MOD) % MOD;
}


ll get_hash_2(int x, int y){
	return (f2[y] - f2[x - 1] * myP[y - x + 1] % MOD + MOD) % MOD;
}


void solve(){
	if (get_hash_1(l, r) == get_hash_2(n - r + 1, n - l + 1)) cout << "YES\n";
	else cout << "NO\n";
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> q;
	n = s.length();
	string rs = string(s.rbegin(), s.rend());

	s = ' ' + s;
	rs = ' ' + rs;

	for (int i = 1; i <= n; i++) 
		f1[i] =  (f1[i - 1] * base + s[i] - 'a' + 1) % MOD;
	for (int i = 1; i <= n; i++) 
		f2[i] =  (f2[i - 1] * base + rs[i] - 'a' + 1) % MOD;

	myP[0] = 1;
	for (int i = 1; i <= n; i++) 
		myP[i] = (myP[i - 1] * base) % MOD;

	while (q--){
		cin >> l >> r;
		cout << get_hash_1(l , r) << '\n';
		cout << get_hash_2(n - r + 1, n - l + 1) << '\n';
		solve();
	}
}
