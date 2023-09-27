/**    
* LANG: C++ 
* author: atom 
* created: 19.05.2022 23:53:48
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
//#include "myLib.h"
#else
#define debug(...) 42
#endif
 
ll a, b;
 
ll dp[20][10][2][2];
 
ll Range(string & y, int n, int pre, bool zero, bool tight){
	if (n == 0)
		return 1;
	if (pre != -1 && dp[n][pre][zero][tight] != -1)
		return dp[n][pre][zero][tight];
	int upper = tight? (y[y.size() - n] - '0') : 9;
 
	ll ans = 0;
	for (int i = 0; i <= upper; i++){
		if (i == pre && zero == 0) continue;
		else if (tight && i == upper) {
			if (zero && (i == 0)) ans += Range(y, n - 1, i, 1, 1);
			else ans += Range(y, n - 1, i, 0, 1);
		} 
		else {
			if (zero && (i == 0)) ans += Range(y, n - 1, i, 1, 0);
			else ans += Range(y, n - 1, i, 0, 0);
		}
	}
	dp[n][pre][zero][tight] = ans;
	return ans;
}
 
int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
 
	cin >> a >> b;
	string A = to_string(a - 1);
	string B = to_string(b);
	memset(dp, - 1, sizeof(dp));
	ll ans = Range(B, B.size(), -1, 1, 1);
	memset(dp, -1, sizeof(dp));
	ans -= Range(A, A.size(), -1, 1, 1);
	cout << ans << '\n';
}
