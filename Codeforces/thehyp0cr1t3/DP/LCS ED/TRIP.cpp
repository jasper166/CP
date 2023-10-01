/**    
* LANG: C++ 
* author: atom 
* created: 26.06.2022 10:35:09
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
constexpr int MAX = 1002;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, m, t, dp[MAX][MAX];
string a, b;
char str[MAX];

void memoi(int x, int y, int L){
	if (L == dp[n][m] + 1){
		L--;
		FOR(i, 1, L) cout << str[i];
		cout << '\n';
		return;
	}
	if (x == n + 1 || y == m + 1) return;
	for (char c = 'a'; c <= 'z'; c++){
		bool flag = false;
		for (int i = x; i <= n; i++){
			if (c == a[i]){
				for (int j = y; j <= m; j++){
					if (c == b[j] && dp[i][j] == L){
						str[L] = c;
						memoi(i + 1, j + 1, L + 1);
						flag = true;
						break;
					}
				}
			}
		if (flag) break;
		}
	}
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> a >> b;
		n = a.size();
		m = b.size();
		a = '$' + a;
		b = '$' + b;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				if (a[i] == b[j]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else 
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}	
		memoi(1, 1, 1); 
	}	 
}
/* problem link: 
	https://www.spoj.com/problems/TRIP/
*/
