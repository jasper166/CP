/**
* LANG: C++
* author: atom
* created: 14.07.2022 14:28:14
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
constexpr int MAX = 1e3 + 2;
constexpr int INF = INT_MAX;

int n, m, k;
pii s;
char a[MAX][MAX];
vector <char> path;
vector < pair< char, pii > > tour = {
	{'D', {1, 0}}, {'L', {0, -1}},
	{'R', {0, 1}}, {'U', { -1, 0}}
};
bool cant = false, vis[MAX][MAX];
int dis[MAX][MAX];
string ret;

int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	ret.resize(k);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'X') s = make_pair(i, j);
		}
	if (k & 1) cant = true;
	else {
		int rem = k;
		queue <pii> q;
		q.push(s);
		dis[s.F][s.S] = 0;
		vis[s.F][s.S] = true;
		while (!q.empty()) {
			pii cur = q.front();
			q.pop();
			for (auto &i : tour) {
				pii next = make_pair(cur.F + i.S.F, cur.S + i.S.S);
				if (1 <= next.F and next.F <= n && 1 <= next.S and next.S <= m) {
					if (!vis[next.F][next.S] and a[next.F][next.S] != '*') {
						dis[next.F][next.S] = dis[cur.F][cur.S] + 1;
						vis[next.F][next.S] = true;
						q.push({next.F, next.S});
					}
				}
			}
		}
		pii cur = {s.F, s.S};
		for (int i = 0; i < k; ++i) {
			cant = true;
			for (int j = 0; j <= 3; j++) {
				pii next = make_pair(cur.F + tour[j].S.F, cur.S + tour[j].S.S);
				debug(cur);
				if (1 <= next.F and next.F <= n && 1 <= next.S and next.S <= m) {
					if (dis[next.F][next.S] <= k - i - 1 && a[next.F][next.S] != '*') {
						ret[i] = tour[j].F;
						cant = false;
						cur.F = next.F;
						cur.S = next.S;
						break;
					}
				}
			}
			if (cant) break;
		}
	}
	if (cant) cout << "IMPOSSIBLE";
	else for (char c : ret) cout << c;
	cout << "\n";
}
/* problem link:

*/

