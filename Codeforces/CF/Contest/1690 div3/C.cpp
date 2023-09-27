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
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		int s[n + 1];
		int f[n + 1];
		s[0] = 0;
		f[0] = 0;
		vector <int> v;
		for (int i = 1; i <= n; i++) cin >> s[i];
		for (int i = 1; i <= n; i++) cin >> f[i];
		for (int i = 1; i <= n; ++i){
			s[i] = max(s[i], f[i - 1]);
			v.pb(f[i] - s[i]);
		}
		for (int i : v) cout << i << ' ';
		cout << '\n';
	} 
}
