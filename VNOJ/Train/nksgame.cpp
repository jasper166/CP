/**    
* LANG: C++ 
* author: atom 
* created: 16.06.2022 09:42:51
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
	int a[n], b[n];
	vector <int> ax, bx;

	FOR(i, 0, n - 1) cin >> a[i];
	FOR(i, 0, n - 1) cin >> b[i];
	ax.pb(*min_element(a, a + n));
	bx.pb(*min_element(b, b + n));
	
	FOR(i, 0, n - 2){
		if (a[i] < 0 && a[i + 1] >= 0) ax.pb(a[i]), ax.pb(a[i + 1]);
	}
	FOR(i, 0, n - 2){
		if (b[i] < 0 && b[i + 1] >= 0) bx.pb(b[i]), bx.pb(b[i + 1]);
	}
	ax.pb(*max_element(a, a + n));
	bx.pb(*max_element(b, b + n));
	// for (int i : ax) cout << i << ' ';
	ll ans = 1e18;
	FOR(i, 0, ax.size() - 1){
		FOR(j, 0, bx.size() - 1) ans = min(ans, 1LL *abs(a[i] + b[j]));
	}
	cout << ans << '\n';
}
