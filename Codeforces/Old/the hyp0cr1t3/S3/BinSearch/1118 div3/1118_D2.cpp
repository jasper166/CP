/**    
* LANG: C++ 
* author: atom 
* created: 12.06.2022 02:36:32
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

int n, s;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> s;
	int a[n];
	FOR(i, 0, n - 1) cin >> a[i];
	sort (a, a + n, greater <int> ());
	ll prefix[n + 1];
	prefix[0] = 0;
	FOR(i, 1, n) prefix[i] = prefix[i - 1] + a[i - 1];
	int ans = -1;
	int l = 1, r = n;
	
	while (l <= r){
		int m = (l + r) >> 1;
		bool ok = false;
		int x = n / m;
		ll pages = 0;

		for (int j = 0; j <= (m - 1) * x - 1; j += x)
			{
				for (int k = 0; k <= x - 1; k++)
				{
					pages += 1LL * max(a[j + k] - k, 0);
					if (pages >= s) break;
				}
			}

		for (int k = (m - 1) * x; k <= n - 1; k++){
			pages += 1LL * max(a[k] - (k - (m - 1) * x), 0);
			if (pages >= s) break;
		}
		// debug(m);
		// debug(pages);
		if (pages >= s){
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << ans << '\n';
}









