/**    
* LANG: C++ 
* author: atom 
* created: 13.06.2022 20:23:05
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
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	int a[n];
	FOR(i, 0, n - 1) cin >> a[i];
	int dp_u[n], dp_d[n];
	memset(dp_u, 0, sizeof(dp_u));
	memset(dp_d, 0, sizeof(dp_d));

	FOR(i, 0, n - 1){
		dp_u[i] = a[i];
		FOR(j, 0, i - 1)
			if (a[i] > a[j])
				dp_u[i] = max(dp_u[i], dp_u[j] + a[i]);
	}
	FORD(i, n - 1, 0){
		dp_d[i] = a[i];
		FORD(j, n - 1, i + 1)
			if (a[i] > a[j])
				dp_d[i] = max(dp_d[i], dp_d[j] + a[i]);
	}
	int ans = 0;
	FOR(i, 0, n - 1)
		ans = max(ans, dp_u[i] + dp_d[i] - a[i]);
	cout << ans << '\n';
}
