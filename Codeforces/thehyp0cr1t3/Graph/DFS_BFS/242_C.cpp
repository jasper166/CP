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
constexpr int MAX = 1e5 + 2;
constexpr int BOUND = 1e9;

pii s, e;
int n;
vector < tuple <int, int, int> > a(MAX);
vector <pii> tour = {
	{1, 0}, {0, 1}, {0, -1}, { -1, 0},
	{1, -1}, {1, 1}, { -1, 1}, { -1, -1}
};

int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> s.F >> s.S >> e.F >> e.S;
	cin >> n;
	map <pii, bool> hash;
	map <pii, int> dis;
	for (int i = 1; i <= n; i++) {
		auto &[x, y, z] = a[i];
		cin >> x >> y >> z;
		for (int j = y; j <= z; j++) hash[ {x, j}] = true;
	}
	// debug(hash);
	dis[ {s.F, s.S}] = 0;
	dis[ {e.F, e.S}] = -1;
	hash[ {s.F, s.S}] = false;
	hash[ {e.F, e.S}] = true;
	queue <pii> q;
	q.push(s);
	while (!q.empty()) {
		pii c = q.front(); q.pop();
		for (pii k : tour) {
			pii u = make_pair(c.F + k.F, c.S + k.S);
			// debug(u);
			if (hash[ {u.F, u.S}]) {
				dis[ {u.F, u.S}] = dis[ {c.F, c.S}] + 1;
				hash[ {u.F, u.S}] = false;
				q.push({u.F, u.S});
			}
		}
	}
	cout << dis[{e.F, e.S}] << "\n";

}
/* problem link:

*/

