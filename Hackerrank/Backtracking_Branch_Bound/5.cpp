/**    
* LANG: C++ 
* author: atom 
* created: 30.05.2022 19:40:32
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

int n, m;
int a[12][12];
int cnt = 0;

void bt(int x, int y){
	if (x == n && y == m){
		cnt++;
		return;
	}
	else {
		if (x + 1 <= n) bt(x + 1, y);
		if (y + 1 <= m) bt(x, y + 1);
	}
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	bt(1, 1);
	cout << cnt << '\n';		 
}
