/**    
* LANG: C++ 
* author: atom 
* created: 18.06.2022 19:31:16
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 2e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

ll dp[MAX];
ll mp[MAX];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	int n;
	cin >> n;
	int a[n];
	FOR(i, 0, n - 1){
		cin >> a[i];
		mp[a[i]]++;
	}
	for (int i = 2; i < MAX; ++i)
		for (int j = i; j < MAX; j += i) dp[i] += mp[j];

	vector <ll> ans;
	FOR(i, 0, n - 1){
		int k = a[i];
		k <<= 1;
		ll res = dp[k] * dp[k];
		res -= dp[k];
		res >>= 1;
		ans.pb(res);  		
	}
	for (ll x : ans) cout << x << ' ';

	cout << '\n';
		 
}
