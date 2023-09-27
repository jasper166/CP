/**    
* LANG: C++ 
* author: atom 
* created: 24.05.2022 07:23:36
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
constexpr int MAX = 1e5 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif


int n, k;
string s;
ll myPow[MAX], myHash[MAX], base = 31;


ll getHash(int i, int j){
	return (myHash[j] - myHash[i - 1] * myPow[j - i + 1] % MOD + MOD) % MOD;
}

bool ok(int m){
	map <ll, ll> mp;
	ll cnt = 1;
	for (int i = 1; i <= n - m + 1; i++){
		ll cmp = getHash(i, i + m - 1);
		mp[cmp]++;
		cnt = max(cnt, mp[cmp]);
		if (cnt >= k) return true;
	}
	return (cnt >= k);
}




int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> n >> k >> s;
	
	s = ' ' + s;

	myPow[0] = 1;
	for (int i = 1; i <= n; i++) myPow[i] = (myPow[i - 1] * base) % MOD;

	for (int i = 1; i <= n; i++)
		myHash[i] = (myHash[i - 1] * base + s[i] - 'a' + 1) % MOD;

	int l = 1, r = n, ans = 0;
	while (l <= r){
		int m = (l + r) / 2;
		if (ok(m)){
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	cout << ans << '\n';
		 
}
