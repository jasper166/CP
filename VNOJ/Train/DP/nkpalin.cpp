/**
* LANG: C++
* author: atom
* created: 17.07.2022 18:43:18
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
constexpr int MAX = 2002;
constexpr int INF = INT_MAX;

int dp[MAX][MAX], n;
string s, ret;
void solve(int i, int j, int l, int r) {
	if (l <= r) {
		if (i == j) ret[l] = s[i];
		else{
			if (s[i] == s[j]){
				ret[l] = ret[r] = s[i];
				solve(i + 1, j - 1, l + 1, r - 1);
			}
			else {
				if (dp[i][j] == dp[i + 1][j])
					solve(i + 1, j, l, r);
				else 
					solve(i, j - 1, l, r);
			}
		}

	}

}

int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> s;
	n = s.size() - 1;
	for (int i = n; i >= 0; i--) {
		for (int j = i; j <= n; j++) {
			if (i == j) {
				dp[i][j] = 1;
			}
			else {
				if (s[i] == s[j]) {
					if (i == j - 1) dp[i][j] = 2;
					else dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	ret.resize(dp[0][n]);
	solve(0, n, 0, dp[0][n] - 1);
	// cout << dp[0][n] << "\n";
	cout << ret << "\n";
}
/* problem link:

*/

