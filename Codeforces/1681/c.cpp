/**    
* LANG: C++ 
* author: atom 
* created: 23.05.2022 21:25:36
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
		int a[n], b[n];
		for (int &i : a) cin >> i;
		for (int &i : b) cin >> i;

		bool flag1 = is_sorted(a, a + n);
		bool flag2 = is_sorted(b, b + n);
		int res;
		vector <pair<int, int>> v;
		for (int i = 0; i <= n - 2; ++i)
			for (int j = i + 1; j <= n - 1; j++)
				if (a[i] >= a[j] && b[i] >= b[j]){
					swap(a[i], a[j]);
					swap(b[i], b[j]);
					v.pb({i, j});
				}
				// for (auto &i : v) cout << i.F << ' ' << i.S << '\n';
				// cout << v.empty() << '\n';
		if (v.empty()){
			if (flag1 && flag2) res = 0;
			else res = -1;
			cout << res << '\n';
		}
		else {
			if (is_sorted(a, a + n) && is_sorted(b, b + n)){
				cout << v.size() << '\n';
				for (auto &i : v) cout << i.F + 1 << ' ' << i.S + 1 << '\n';
			}
			else cout << "-1\n";
		}

	}
		 
}
