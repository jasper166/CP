/**    
* LANG: C++ 
* author: atom 
* created: 01.06.2022 14:19:41
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
#define int long long 

int n, t, k;
bool cmp(pair<vector <int>, int> a, pair<vector <int>, int> b){
	return (a.S < b.S);
}


int32_t orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		cin >> n;
		vector <pair<vector<int>, int>> a;
		for (int i = 0; i <= n - 1; i++){
			cin >> k;
			int inf = -1;
			vector <int> tmp(k);
			for (int j = 0; j <= k - 1; j++){
				cin >> tmp[j];
				inf = max(inf, tmp[j] - j + 1);
			}
			a.pb({tmp, inf});
		}
		sort(all(a), cmp);
		int l = 0, r = 1e18, ans = 1e18;
		while (l <= r){
			int m = (l + r) >> 1;
			bool ok = true;
			int tmp = m;
			for (int i = 0; i <= n - 1; i++){
				if (tmp < a[i].S){
					ok = false;
					break;
				}
				else tmp += a[i].F.size();
			}
			if (ok){
				ans = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		cout << ans << '\n';
	}
}
