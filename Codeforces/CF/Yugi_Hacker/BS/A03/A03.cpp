/**    
* LANG: C++ 
* author: atom 
* created: 21.05.2022 16:18:38
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
constexpr int MAX = 2 * 1e5 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

	
int n, k, half;
int a[MAX];

bool ok(int m){
	int sum = 0;
	for (int i = half; i >= 0; --i){
		if (m >= a[i]) 
			sum += (m - a[i]); 
	}
	return (sum <= k);	
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	cin >> n >> k;
	for (int i = 0; i <= n - 1; ++i) cin >> a[i];
	half = n / 2;
	sort(a, a + n, greater <int> ());

	int l = 0, r = 1e9 + 2, res = 0;
	while (l <= r){
		int m = (r + l) / 2;
		if (ok(m)) res = m, l = m + 1;
		else r = m - 1;
	}	
	cout << res << '\n';
}
