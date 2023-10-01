/**    
* LANG: C++ 
* author: atom 
* created: 16.06.2022 14:22:59
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

int n, q, l, r;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> q;
	int a[n + 1];
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int cnt[n + 1] = {0}, freq[n + 1] = {0};
	while (q--){
		cin >> l >> r;
		// cout << l << r << '\n';
		cnt[l]++;
		if (r < n) cnt[r + 1]--;
	}
	
	FOR(i, 1, n) freq[i] = freq[i - 1] + cnt[i];
	
	sort(freq + 1, freq + 1 + n);
	
	ll ans = 0;
	FOR(i, 1, n) ans += 1LL * a[i] * freq[i];
	cout << ans << '\n';
}
