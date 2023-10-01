/**    
* LANG: C++ 
* author: atom 
* created: 22.05.2022 21:30:33
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

int t, n;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--){
		cin >> n;
		int a[n];
		for (int &i : a) cin >> i;
		int ans = -1;
		for (int i = 0; i <= n - 1; ++i)
			if (a[i] != i){
				ans = a[i];
				break;
			}
		int res = -1;
		for (int i = 0; i <= n - 1; i++)
			if (a[i] != i){
				ans &= a[i];
				res = max(ans, res);
			}
		cout << ans << '\n'; 
	}
		 
}
