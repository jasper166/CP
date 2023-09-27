/**    
* LANG: C++ 
* author: atom 
* created: 12.06.2022 00:36:56
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

int n, s;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> s;
	int a[n];
	FOR(i, 0, n - 1) cin >> a[i];
	int l = 1, r = n, ans_num = 0, ans_cost = 0;
	while (l <= r){
		int m = (l + r) >> 1;
		bool ok = false;

		int cost = 0, cnt = 0;
		vector <int> new_a(n);
		FOR(i, 0, n - 1) new_a[i] = a[i] + (i + 1) * m;
		sort (all(new_a));

		FOR(i, 0, n - 1){
			cost += new_a[i];
			cnt++;
			if (cost >= s || cnt >= m) break;
		}
		debug(cost);
		debug(m);
		debug(cnt);
		if (cnt == m && cost <= s) ok = true;


		if (ok){
			ans_num = m;
			ans_cost = cost;
			l = m + 1;
		}
		else r = m - 1;
	}
	cout << ans_num << ' ' << ans_cost << '\n';
		 
}
