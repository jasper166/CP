/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 09:56:51
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
constexpr int MAX = 1e3 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, k;
string s;
int used[MAX];


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--){
		cin >> n >> k;
		int a[n + 1];
		ll ans = 0;
		for (int i = 1; i <= n; ++i){
			cin >> a[i];
			ans += a[i] / k;
			used[a[i] % k]++;
		}
		for (int i = 1; i < (k + 1) / 2; i++){
			used[k - i] += used[k - i + 1];
			used[k - i + 1] = 0;
			int mini = min(used[i], used[k - i]);
			ans += mini;
			used[i] = 0;
			used[k - i] -= mini;
		}
		used[(k + 1) / 2] += used[(k + 1)/ 2 + 1];
		used[(k + 1)/ 2 + 1] = 0;
		ans += used[(k + 1) / 2] / 2;
		cout << ans << '\n';
		used[(k + 1) / 2] = 0;

	} 
}
