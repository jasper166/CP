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
int ans = 0;
int n;
void queens(int y){
	if (y == n + 1){
		ans++;
		return;
	}
	for (int x = 1; x <= n; x++){
		if (!col[x] || !diag1[x + y] || !diag2[x - y + n - 1]) continue;
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
		queens(y + 1);	
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
	}
}





int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	memset(col, true, sizeof(col));
	memset(diag2, true, sizeof(diag2));
	memset(diag1, true, sizeof(diag1));
	
	queens(1);
	cout << ans << '\n';

}
