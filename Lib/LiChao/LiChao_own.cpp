// Easiest forimplementing and understanding
const ll inf = 1e18;

struct LiChaoTree {
 // Min
    struct Line {
        ll a, b;
        Line(ll _a = 0, ll _b = inf) : a(_a), b(_b) {};
        ll cal(ll x) { return a * x + b; }      
    };
    int n;
    vector <Line> f;
    LiChaoTree(int _n) {
        n = _n;
        f.resize(_n * 4 + 5);
    }

    void addLine(int x, int lx, int rx, Line line) {
        if (lx == rx) {
            if (f[x].cal(lx) > line.cal(lx))
                f[x] = line;
            return;
        }
        int m = (lx + rx) >> 1;
        if (f[x].a < line.a) swap(f[x], line);
        if (line.cal(m) < f[x].cal(m)) {
            swap(f[x], line);
            addLine(x << 1, lx, m, line);
        }
        else addLine(x << 1 | 1, m + 1, rx, line);
    }

    void addRange(int x, int l, int r, int u, int v, Line line) {
        if (l > v || r < u) return;
        if (u <= l && r <= v) {
            addLine(x, l, r, line);
            return;
        }
        int m = (l + r) >> 1;
        addRange(x << 1, l, m, u, v, line);
        addRange(x << 1 | 1, m + 1, r, u, v, line);
    }

    ll qry(int x, int lx, int rx, int p) {
        ll ans = f[x].cal(p);
        if (lx == rx) return ans;
        int m = (lx + rx) >> 1;
        if (p <= m) return min(ans, qry(x << 1, lx, m, p));
        else return min(ans, qry(x << 1 | 1, m + 1, rx, p));
    }

    ll qry(int x) { return qry(1, 1, n, x); }
    void addRange(int l, int r, ll a, ll b) { addRange(1, 1, n, l, r, Line(a, b)); }
    void addLine(ll a, ll b) { addLine(1, 1, n, Line(a, b)); }
};