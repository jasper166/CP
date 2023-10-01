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
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

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
	__int128 qry(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return (__int128) l.a * x + l.b;
	}
};

int n;
ll S;
pii b[MAX];
pair <ll, ll> dp[MAX];
// dp(i) : <min time reach i, cookies having at that time>
void run_case() {
    cin >> n >> S;
    for (int i = 1; i <= n; ++i) cin >> b[i].se >> b[i].fi;
    sort(b + 1, b + 1 + n);

    DynamicHull hull;
    dp[1] = {0, 0};
    hull.add(b[1].se, -dp[1].fi * b[1].se + dp[1].se);
    for (int i = 2; i <= n; ++i) {
        ll lb = dp[i - 1].fi, rb = S;
        while (lb < rb) {
            ll m = (lb + rb) / 2;
            if (hull.qry(m) >= b[i].fi)
                rb = m;
            else
                lb = m + 1;
        }
        ll cookies = hull.qry(lb);
        dp[i] = make_pair(lb, cookies - b[i].fi);
        hull.add(b[i].se, -dp[i].fi * b[i].se + dp[i].se);
    }
    ll ans = INF;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, (S - dp[i].se + b[i].se - 1) / b[i].se + dp[i].fi);
    cout << ans << "\n";
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
