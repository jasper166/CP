/**    
* LANG: C++ 
* author: atom 
* created: 03.06.2022 20:00:36
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

int n, t;
string s;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		cin >> n;
		vector <string> v;
		int pos = 0, i = 1;

		int dp[n + 1][4];
		dp[0][0] = 0;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= 3; j++){
				if (i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = (dp[i - 1][j] % MOD + dp[i - 1][j - 1] % MOD) % MOD;
			}
		}			


		while (i <= 2 *n){
			string tmp;
			cin >> tmp;
			for (char j : tmp) pos ^= j;
			v.pb(tmp);
			i++;
		}
		cin >> s;
		for (char j : s) pos ^= j;
		char ans = pos;
		cout << ans << '\n';
	}

		 
}
