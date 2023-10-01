/**    
* LANG: C++ 
* author: atom 
* created: 04.06.2022 17:24:57
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

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int a[n + 1];
	int pos[n + 1];
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		pos[a[i]] = i;
	}
	vector <int> dp(n + 1, 1);
	for (int i = 1; i <= n; i++){
		for (int j = a[i]; j <= n; j += a[i]){
			if (pos[j] > i)
				dp[j] = max(dp[a[i]] + 1, dp[j]);
		}
	}
	debug(dp);
	cout << *max_element(all(dp)) << '\n';
}
