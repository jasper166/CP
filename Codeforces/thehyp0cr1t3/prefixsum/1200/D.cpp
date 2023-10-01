/**    
* LANG: C++ 
* author: atom 
* created: 23.06.2022 10:05:05
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
#define end cout << '\n'
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, k;
char a[2002][2002];
vector <pii> row, col;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}

	int ans = 0;
	// Row
	row.pb({0, 0});
	col.pb({0, 0});
	for (int k = 1; k <= n; k++){
		int i = 1, j = n;
		for (; i <= n; i++)
			if (a[k][i] == 'B') break;
		for (; j >= 1; j--)
			if (a[k][j] == 'B') break;
		row.pb({i, j});
	}
	for (int k = 1; k <= n; k++){
		int i = 1, j = n;
		for (; i <= n; i++)
			if (a[i][k] == 'B') break;
		for (; j >= 1; j--)
			if (a[j][k] == 'B') break;
		col.pb({i, j});
	}
	// count the already white painted lines.
	// debug(row);
	for (int i = 1; i <= n; i++){
		if (row[i].F == n + 1 && row[i].S == 0) ans++;
		if (col[i].F == n + 1 && col[i].S == 0) ans++;
	}
	int cnt[n + 1][n + 1] = {0};

	// condition for the row is white after cell [i][j] is clicked,
	// row at i, i + k - 1
	// j <= l <= r <= j + k - 1
	debug(row);
	for (int j = 1; j <= n - k + 1; j++){
		int cur = ans;
		// calculate row in the first slide: k * k.
		for (int i = 1; i <= k; i++){
			if (j <= row[i].F && j <= row[i].S && row[i].S <= j + k - 1) cur++;
		}
		for (int i = 1; i <= n - k + 1; i++){
			if (i >= 2){
				if (j <= row[i - 1].F && j <= row[i - 1].S && row[i - 1].S <= j + k - 1) 
					cur--;
				// cout << i << ' ' << j << ' ' << cur << '\n';
				if (j <= row[i + k - 1].F && j <= row[i + k - 1].S && row[i + k - 1].S <= j + k - 1)
					cur++;
			}
			cnt[i][j] = cur;
		}
	}
	for (int i = 1; i <= n - k + 1; ++i){
		int cur = 0;
		for (int j = 1; j <= k; j++){
			if (i <= col[j].F && i <= col[j].S && col[j].S <= i + k - 1) cur++;
		}
		for (int j = 1; j <= n - k + 1; ++j){
			if (j >= 2) {
				if (i <= col[j - 1].F && i <= col[j - 1].S && col[j - 1].S <= i + k - 1) cur--;
				if (i <= col[j + k - 1].F && i <= col[j + k - 1].S && col[j + k - 1].S <= i + k - 1) cur++;
			}
			cnt[i][j] += cur;
			ans = max(ans, cnt[i][j]);
		}
	}

	// FOR(i, 1, n){
	// 	FOR(j, 1, n){
	// 		cout << cnt[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	cout << ans << '\n';	 
}
// problem link: https://codeforces.com/contest/1200/problem/D
