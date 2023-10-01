/**    
* LANG: C++ 
* author: atom 
* created: 04.06.2022 17:59:02
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

int n, k;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	int a[MAX];
	ll dp[MAX], sum = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i], sum += 1LL * a[i];
	deque <int> dq;
	dq.pb(0);
	for (int i = 1; i <= n + 1; i++){
		if (i - k - 1 > dq.front()) dq.pop_front();
		dp[i] = dp[dq.front()] + a[i];
		while (dq.size() && dp[dq.back()] > dp[i])
			dq.pop_back();
		dq.pb(i);
	}
	debug(sum);
	debug(dp[n + 1]);
	cout << sum - dp[n + 1] << '\n';		 
}
