/**    
* LANG: C++ 
* author: atom 
* created: 04.06.2022 08:09:56
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


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n];
	for (int &i : a) cin >> i;
	int dp[n];
	for (int i = 0; i <= n - 1; i++){
		dp[i] = 1;
		for (int j = 0; j < i; j++){
			if (a[j] < a[i]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << *max_element(dp, dp + n) << '\n';
		 
}
