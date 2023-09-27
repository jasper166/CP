/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 18:11:08
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

int n, s;

int ans = -1e9;


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;	
	int w[n], v[n];
	for (int &i : w) cin >> i;
	for (int &i : v) cin >> i;

	for (int i = 0; i <= (1 << n) - 1; i++){
		int cur = 0, bp = 0;
		for (int j = 0; j <= n - 1; j++){
			if (i & (1 << j)){
				bp += w[j];
				cur += v[j]; 
			}
		}
		if (bp <= s) ans = max(ans, cur);
	}
	cout << ans << '\n';	 
}
