/**    
* LANG: C++ 
* author: atom 
* created: 01.06.2022 21:43:37
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
ll a[MAX];

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];

		int l = 0, r = n, ans = n;
		while (l <= r){
			int m = (l + r) >> 1;
			bool ok = false;
			

				
			if (ok){
				ans = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		cout << ans << '\n';
	}		 
}
