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

int n, m, t, l, r;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	int a[n];
	FOR(i, 0, n - 1) cin >> a[i];
	ll pre1[n + 1], pre2[n + 1];
	pre1[0] = pre2[0] = 0;
	FOR(i, 1, n)
		pre1[i] = pre1[i - 1] + a[i - 1];
	sort(a, a + n);
	FOR(i, 1, n)
		pre2[i] = pre2[i - 1] + a[i - 1]; 
	cin >> m;
	while (m--){
		cin >> t >> l >> r;
		if (t == 1) cout << pre1[r] - pre1[l - 1] << '\n';
		else cout << pre2[r] - pre2[l - 1] << '\n';
	}
}
