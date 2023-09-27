/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 20:30:41
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

	int a[4];

	for (int i = 0; i <= 3; i++) cin >> a[i];
	int ans = -1e9;

	for (int i = 0; i <= 7; i++){
		int sum = a[0];
		for (int j = 0; j <= 2; j++){
			if (i & (1 << j)) sum += a[j + 1];
			else sum -= a[j + 1];
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';
}
