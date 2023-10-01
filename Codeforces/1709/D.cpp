/**
* LANG: C++
* author: atom
* created: 21.07.2022 18:47:39
**/
#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define travel(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

#define orz main
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pob pop_back
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert


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
void __print(const pair<T, V> &x) {cerr << "{"; __print(x.first); cerr << ", "; __print(x.secondecond); cerr << "}\n";}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cout << "#L" <<__LINE__<< ":" <<" [" << #x << "]=\n" <<"["; _print(x); cout << '\n';
#else
#define debug(...) 42
#endif


constexpr int MOD = (int) 1e9 + 7;
constexpr int INF = (int) 1e9;
constexpr int MAX = (int) 1e6 + 2;

int a[MAX], n;
int q, m, k;
pii x, y;
struct Segtree {
	int st[MAX * 4];
//	int lazy[400000 + 20];
	void build(int id, int l, int r) {
		if (l == r) {
			st[id] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		st[id] = max(st[id * 2], st[id * 2 + 1]);
	}
	void update(int id, int l, int r, int i, int v) {
		if (i < l || r < i) {
			return ;
		}
		if (l == r) {
			st[id] = v;
			return ;
		}

		int mid = (l + r) / 2;
		update(id * 2, l, mid, i, v);
		update(id * 2 + 1, mid + 1, r, i, v);
		st[id] = max(st[id * 2], st[id * 2 + 1]);
	}
	void update(int i, int v) {
		update(1, 1, n, i, v);
	}
	int query(int id, int l, int r, int L, int R) {
		if (R < l || r < L) {
			return -INF;
		}
		if (L <= l && r <= R) {
			return st[id];
		}
		int mid = (l + r) / 2;
		return max(query(id * 2, l, mid, L, R), query(id * 2 + 1, mid + 1, r, L, R));
	}
	int query(int L, int R) {
		return query(1, 1, n, L, R);
	}
} ST;



void run_case() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ST.build(1, 1, n);
	cin >> q;
	while (q--) {
		cin >> x.first >> y.first >> x.second >> y.second >> k;
		if ((x.second - x.first) % k || (y.second - y.first) % k) {
			cout << "NO\n";
			continue;
		}
		if (y.first == y.second) {
			cout << "YES\n";
			continue;
		}
		x.first += k * ((m - x.first) / k);
		if (y.first >= y.second) swap(y.first, y.second);
		cout <<((ST.query(y.first, y.second) < x.first)? "YES" : "NO")<< "\n";
	}
}

int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);


	int Test = 1;
	// cin >> Test;
	while (Test--) {

		run_case();
	}


}
/* problem link:

*/

