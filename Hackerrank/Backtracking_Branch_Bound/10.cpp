/**    
* LANG: C++ 
* author: atom 
* created: 31.05.2022 07:02:52
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

int n;
ll a[22][22], ans = 1e9;
bool visited[20];

void tsp(int cur, ll cost, int cnt){
	if (cnt == n && a[cur][1]){
		// cout << cnt << '\n';
		ans = min(ans, a[cur][1] + cost);
		return;
	}
	for (int i = 1; i <= n; i++){
		if (visited[i] && a[cur][i]){
			if (cost + a[cur][i] > ans) continue;
			visited[i] = false;
			tsp(i, cost + a[cur][i], cnt + 1);
			visited[i] = true;
		}
	}
}



int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) cin >> a[i][j];
	memset(visited, true, sizeof(visited));
	visited[1] = false;

	tsp(1, 0, 1);
	cout << ans << '\n';		
		 
}
