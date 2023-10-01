/**    
* LANG: C++ 
* author: atom 
* created: 24.05.2022 20:20:03
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

int t, n;
string s, rs;
ll f1[MAX], f2[MAX], base = 31, myPow[MAX];

ll get_hash_1(int i, int j){
	return (f1[j] -  f1[i - 1] * myPow[j - i + 1] % MOD + MOD) % MOD;
}


ll get_hash_2(int i, int j){
	return (f2[j] -  f2[i - 1] * myPow[j - i + 1] % MOD + MOD) % MOD;
}

bool isPalin(int i){
	for (char c = 'a'; c <= 'z'; c++){
		// ll hash 
		ll hash_1 = ((f1[i] * myPow[n - i + 1]) % MOD 
					+ ((c - 'a' + 1) * myPow[n - i]) % MOD
					+ get_hash_1(i + 1 , n)) % MOD;
		ll hash_2 = ((f2[n - i] * myPow[i + 1]) % MOD 
					+ ((c - 'a' + 1) * myPow[i]) % MOD
					+ get_hash_2(n - i + 1, n)) % MOD;
		// cout << "i: " << i << " " << hash_1 << " " << hash_2<< '\n';
		if (hash_1 == hash_2) return true;
	} 
	return false;
}

ll gethash(string s){
	ll ans = 0;
	for (int i = 0; i <= (int) s.length() - 1; ++i){
		ans = (ans * base + s[i] - 'a' + 1) % MOD;
	}
	return ans;
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	cin.ignore();
	while (t--){
		cin >> s;
		int ans = 0;
		n = s.length();
		
		rs = string(s.rbegin(), s.rend());
		
		s = ' ' + s;
		rs = ' ' + rs;
		// cout << s << rs << '\n';
		myPow[0] = 1;
		for (int i = 1; i <= n; i++){
			f1[i] = (f1[i - 1] * base + s[i] - 'a' + 1) % MOD;
			f2[i] = (f2[i - 1] * base + rs[i] - 'a' + 1) % MOD;
			myPow[i] = (myPow[i - 1] * base) % MOD;
		}
		myPow[n + 1] = (myPow[n] * base) % MOD;
		for (int i = 0; i <= n; ++i){
			if (isPalin(i)) ans++;
		}
		cout << ans << '\n';
	}
	// cout << gethash("aaaa") << '\n';
		 
}
