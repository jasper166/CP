/**
* LANG: C++
* author: atom
* created: 18.07.2022 06:57:19
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
constexpr int MAX = 105;
constexpr int INF = INT_MAX;

int n, m;
int a[MAX][MAX], b[MAX][MAX];
int dp[MAX][MAX];
pii t[] = {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};



int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n >> m;
	// memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
			char c;
			cin >> c;
			if (c == '*'){
				a[i][j] = 1;
				b[i][j] = 1;
			}
	}
	vector <pair <pii, int>> ret;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++){
		int sz = 0;
		while (a[i - sz][j] && a[i][j - sz] && a[i + sz][j] && a[i][j + sz]) 
			sz++;
		if (sz >= 2){
			ret.emplace_back(make_pair(i, j), sz - 1);
			for (int k = 0; k < sz; k++){
				b[i - k][j] = 0;
				b[i][j - k] = 0;
				b[i + k][j] = 0;
				b[i][j + k] = 0;
			}
		}
	}
	bool cant = false;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++){
		if (b[i][j] == 1){
			cant = true;
			break;
		}
	}
	if (cant) cout << "-1\n";
	else {
	cout << ret.size() << "\n";
	for (auto it : ret)
		cout << it.F.F << " " << it.F.S << " " << it.S << "\n"; 
	}
}
/* problem link:

*/

