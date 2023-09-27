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
const int MAX = 2e5 + 5;

const ll inf = (ll) 1e18;
struct LiChaoTree {
    // Query for min;
    int sz;
    struct Line {
        ll a, b;
        Line() : a(0), b(inf) {}
        Line(ll _a, ll _b) : a(_a), b(_b) {}
        ll cal(ll x) { return a * x + b; }
    };

    struct Node {
        Line line;
        Node *lc, *rc;
        Node() : line(Line()), lc(nullptr), rc(nullptr) {};
        Node(const Line _line) : line(_line), lc(nullptr), rc(nullptr) {};
    } *root;

    LiChaoTree (int N) : sz(N), root(new Node()) {};

    void add(Node *p, int l, int r, Line line) {
        if (p == nullptr) {
            p = new Node(line);
            return;
        }
        if (l == r) {
            if (line.cal(l) < p->line.cal(l))
                p->line = line;
            return;
        }
        int m = (l + r) >> 1;
        if (line.a > p->line.a) swap(line, p->line);
        if (line.cal(m) < p->line.cal(m)) {
            swap(line, p->line);
            add(p->lc, l, m, line);
        }
        else
            add(p->rc, m + 1, r, line);
    }

    ll qry(Node *p, int l, int r, int x) {
        if (p == nullptr) return inf;
        if (l == r) return p->line.cal(x);
        ll ans = p->line.cal(x);
        int m = (l + r) >> 1;
        if (x <= m) return min(ans, qry(p->lc, l, m, x));
        else return min(ans, qry(p->rc, m + 1, r, x));
    }
    void add(ll a, ll b) { add(root, 1, sz, Line(a, b)); }
    ll qry(ll x) { return qry(root, 1, sz, x); }
};

int n, d;
int s[MAX], f[MAX];
ll dp[MAX];
void run_case() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) cin >> f[i];

    int sz = *max_element(s + 1, s + 1 + n);
    LiChaoTree lc(sz);
    lc.add(d, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = lc.qry(s[i]);
//        debug(dp[i]);
        lc.add(f[i], dp[i]);
    }
    cout << dp[n] << "\n";
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
