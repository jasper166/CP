#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

struct Line {
	mutable ll a, b, p;
	bool operator<(const Line& o) const { return a < o.a; }
	bool operator<(ll x) const { return p < x; }
};

struct DynamicHull : multiset<Line, less<>> {
    // Maintain to get maximum
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->a == y->a) x->p = x->b > y->b ? inf : -inf;
		else x->p = div(y->b - x->b, x->a - y->a);
		return x->p >= y->p;
	}
	void add(ll a, ll b) {
		auto z = insert({a, b, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll qry(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.a * x + l.b;
	}
};

DynamicHull hull[MAX];
int n;
int a[MAX], b[MAX];
vector <int> adj[MAX];
ll dp[MAX];
int sz[MAX];
void reSubsize(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v ^ p) {
            reSubsize(v, u);
            sz[u] += sz[v];
        }
    }
}

void dfs(int u, int p) {
    int bigC = 0;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs(v, u);
            if (sz[bigC] < sz[v]) {
                bigC = v;
            }
        }
    }
    // A leaf found
    if (!bigC) {
        hull[u].clear();
        dp[u] = 0;
        hull[u].add(-b[u], 0);
        return;
    }

    hull[u] = hull[bigC];
    for (int v : adj[u]) {
        if (v ^ p && v ^ bigC) {
            for (Line line : hull[v]) {
                hull[u].add(line.a, line.b);
            }
        }
    }
    dp[u] = -hull[u].qry(a[u]);
    hull[u].add(-b[u], -dp[u]);
}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    reSubsize(1, 0);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
//        debug(sz[i]);
        cout << dp[i] << " \n"[i == n];
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

