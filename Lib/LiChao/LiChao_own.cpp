// Easiest to implementing and understanding
const ll inf = (ll) 1e18;
struct LiChaoTree {
    // Query for min;
    struct Line {
        ll a, b;
        Line() : a(0), b(inf) {}
        Line(ll _a, ll _b) : a(_a), b(_b) {}
        ll cal(ll x) { return a * x + b; }
    };
    int n;
    vector <Line> f;
    LiChaoTree(int N) : n(N), f(n * 4 + 5) {};
    void add(int x, int lx, int rx, Line line) {
        if (lx == rx) {
            if (line.cal(lx) < f[x].cal(lx))
                f[x] = line;
            return;
        }
        int m = (lx + rx) >> 1;
        if (line.a > f[x].a) swap(line, f[x]);
        if (line.cal(m) < f[x].cal(m)) {
            swap(line, f[x]);
            add(x << 1, lx, m, line);
        }
        else add(x << 1 | 1, m + 1, rx, line);
    }

    ll qry(int x, int lx, int rx, int p) {
        ll ans = f[x].cal(p);
        if (lx == rx) return ans;
        int m = (lx + rx) >> 1;
        if (p <= m) return min(ans, qry(x << 1, lx, m, p));
        else return min(ans, qry(x << 1 | 1, m + 1, rx, p));
    }
    void add(ll a, ll b) { add(1, 1, n, Line(a, b)); }
    ll qry(ll x) { return qry(1, 1, n, x); }

};