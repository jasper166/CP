/**    
* LANG: C++ 
* author: atom 
* created: 26.06.2022 18:22:38
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
#define end cout << '\n'
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 3e5 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, a[40];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	int sum = 0, ans = 1e9;
	map <int, int> mp;
	FOR(i, 0, n - 1) cin >> a[i], sum += a[i];

	for (int i = 0; i < (1 << n); i++){
		int sum2 = 0;
		for (int j = 0; j < n; j++){
			if (i & (1 << j)){
				sum2 += a[j];
			}
		}
		ans = min(ans, abs(2 * sum2 - sum));
		mp[abs (2 * sum2 - sum)]++;
	}	

	// debug(mp) 
	cout << ans << " " << mp[ans] / 2 << '\n';
}
/* problem link: 

*/
