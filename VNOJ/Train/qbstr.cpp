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

string a, b;
int dp[2002][2002];

int memoi(int n, int m){
	if (n == -1 || m == -1) return 0;
	if (dp[n][m] != -1) return dp[n][m];
	if (a[n] == b[m]) return 1 + memoi(n - 1, m - 1);
	else return dp[n][m] = max(memoi(n - 1, m), memoi(n, m - 1));
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> a >> b;
	int n = a.size(), m = b.size();
	memset(dp, -1, sizeof(dp));
	a = '$' + a;
	b = '$' + b;
	FOR(i, 0, n){
		FOR(j, 0, m){
			if (i == 0 || j == 0) dp[i][j] = 0;
			else {
				if (a[i] == b[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[n][m] << '\n';
		 
}
