/**
* LANG: C++
* author: atom
* created: 18.07.2022 20:42:00
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << "{"; __print(x.first); cerr << ", "; __print(x.second); cerr << "}\n";}
template<typename T>
void __print(const T &x) {
	int f = 0;
	cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";
}

void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cout << "#L" <<__LINE__<< ":" <<" [" << #x << "]=\n" <<"["; _print(x); cout << '\n';
#else
#define debug(...) 42
#endif

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 2;
constexpr int INF = 1e9;
int t, n, k;
// int n, k, a[MAX], p[MAX];
vector < int > a;
bool check(int m) {
	for (int i = 0; i + m <= a[n]; i++) {
		bool flag = true;
		int l = i, r = i + m;
		for (int j = 1, R, p; j <= n; j++) {
			if (l)
				R = a[j] / l;
			else
				R = INF;
			p = a[j] / (r + 1) + 1;
			if (p > R || p > k) {
				flag = false;
				break;
			}
		}
		if (flag) 
			return true;
	}
	return false;
}

void solve() {
	cin >> n >> k;
	a.resize(n + 1);
	int maxi = -INF, mini = INF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ckmax(maxi, a[i]);
		ckmin(mini, a[i]);
	}
	int l = 0, r = maxi - mini;
	int ret = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m)) {
			r = m - 1;
			ret = m;
		}
		else l = m + 1;
	}
	cout << ret << "\n";
}



int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--) {
		solve();
	}


}
/* problem link:

*/

