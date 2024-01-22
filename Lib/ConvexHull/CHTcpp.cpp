// Query for max, slope increasing;
struct ConvexHull {
    struct Line {
        ll a, b;
        Line (ll _a = 0, ll _b = 0) { a = _a; b = _b; };
        ll cal(ll x) { return a * x + b; }
        long double cross(Line o) { return (long double) (b - o.b) / (long double) (o.a - a); }
    };
    deque <Line> q;
    void add(Line nLine) {
        // need to change when a is increasing or decreasing
        while (q.size() >= 2 
            && (q.back().cross(nLine) <= q.back().cross(q[q.size() - 2]) 
                || (q.back().a == nLine.a && q.back().b <= nLine.b)))
            q.pop_back();
        q.push_back(nLine);
    }
    ll qry(ll x) {
        while (q.size() >= 2 && q[0].cal(x) <= q[1].cal(x))
            q.pop_front();
        return q[0].cal(x);
    }
};