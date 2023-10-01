//Using when rolling back
// Problem : https://oj.vnoi.info/problem/harbinge
// query for min, decreasing slope
struct CHT {
    struct Line {
        ll a, b;
        Line (ll _a = 0, ll _b = 0) { a = _a; b = _b; };
        ll cal(ll x) { return a * x + b; }
        long double cross(Line o) { return (long double) (b - o.b) / (long double) (o.a - a); }
    };

    Line q[MAX];

    struct Pre {
        int pos, top;
        Line past;
        Pre (int a, int b, Line c) : pos(a), top(b), past(c) {};
    };

    vector <Pre> undo;
    int top;

    void add(ll a, ll b) {
        Line nLine(a, b);
        int pos = top + 1;
        int l = 2, r = top;
        while (l <= r) {
            int m = (l + r) / 2;
            if (q[m - 1].cross(nLine) <= q[m - 1].cross(q[m])) {
                pos = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        undo.push_back({pos, top, q[pos]});
        q[pos] = nLine;
        top = pos;
    }

    void roll_back() {
        if (undo.empty()) return;
        Pre x = undo.back(); undo.pop_back();
        top = x.top;
        q[x.pos] = x.past;
    }

    ll qry(ll x) {
        int l = 1, r = top;
        ll ans = q[l].cal(x);
        while (l < r) {
            int m = (l + r) / 2;
            ll lhs = q[m].cal(x);
            ll rhs = q[m + 1].cal(x);
            if (lhs > rhs)
                l = m + 1;
            else
                r = m;
            ans = min({ans, lhs, rhs});
        }
        return ans;
    }
} hull;


struct CHT {
    struct Line {
        ll a, b;
        Line(ll _a, ll _b) : a(_a), b(_b) {};
        ll cal(ll x) { return a * x + b; }
        double cross(Line o) { return (double) (b - o.b) / (double) (o.a - a); }
    };

    deque <Line> q;
    void add(ll a, ll b) {
        Line nLine(a, b);
        while (q.size() >= 2 && q[0].cross(nLine) <= q[0].cross(q[1]))
            q.pop_front();
        q.push_front(nLine);
    }
    ll qry(ll x) {
        int l = 0, r = q.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (q[m].cal(x) > q[m + 1].cal(x))
                l = m + 1;
            else
                r = m;
        }
        return q[l].cal(x);
    }
};