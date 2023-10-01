/**    
* LANG: C++ 
* author: atom 
* created: {command:date +"%d.%m.%Y %H:%M:%S"}
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
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, k;

bool ok(ll m, int *a){
	ll cost = 0;
	FOR(i, n / 2, n - 1){
		cost += max(m - 1LL * a[i], 0LL);
		if (cost > k) return false;
	}
	return cost <= k;
}


int orz(){
	scanf("%d%d", &n, &k);
	int a[n];
	FOR(i, 0, n - 1) scanf("%d", &a[i]);
	sort(a, a + n);
	ll l = 0, r =  1e18, ans = 1e18;
	while (l <= r){
		ll m = (l + r) >> 1;
		if (ok(m, a)){
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	printf("%lld\n", ans);
}
