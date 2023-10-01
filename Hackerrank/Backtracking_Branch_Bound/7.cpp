/**    
* LANG: C++ 
* author: atom 
* created: 30.05.2022 22:21:49
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

bool col[20], row[20], diag1[40], diag2[40];
int ans = 0, n;
int a[9][9];

void queens(int y, int cur){
	if (y == n + 1){
		ans = max(ans, cur);
		return;
	}
	for (int x = 1; x <= n; x++){
		if (!col[x] || !diag1[x + y] || !diag2[x - y + n - 1]) continue;
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
		queens(y + 1, cur + a[x][y]);	
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
	}
}





int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	n = 8;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	memset(col, true, sizeof(col));
	memset(diag2, true, sizeof(diag2));
	memset(diag1, true, sizeof(diag1));
	
	queens(1, 0);
	cout << ans << '\n';

}
