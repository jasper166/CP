/**
* LANG: C++
* author: atom
* created: 15.07.2022 14:33:30
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb emplace_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;

int q, n;
string s, t;
int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	auto solve = [] () {
		ll ret = 0;
		bool cant = false;
		vector <int> x, y;
		for (int i = 1; i < n; i++){
			if (s[i - 1] != s[i]) x.emplace_back(i);
			if (t[i - 1] != t[i]) y.emplace_back(i);
		}
		if (x.size() != y.size() or s[0] != t[0] or s[n - 1] != t[n - 1]){
			cant = true;
		}
		else {
			for (int i = 0 ; i < (int) x.size(); i++)
				ret += abs(x[i] - y[i]);
		}
		ret = cant ? -1 : ret;
		cout << ret << "\n";
	};

	cin >> q;
	while (q--) {
		cin >> n >> s >> t;
		solve();
	}


}
/* problem link:

*/

