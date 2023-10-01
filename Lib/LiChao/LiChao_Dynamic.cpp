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