struct Line {
    ll a, b;
    Line (ll _a, ll _b) {
        a = _a;
        b = _b;
    }
    ll cal(ll x) {
        return (a * x + b); 
    }
    long double cross(Line o) {
        return (long double) (b - o.b) / (o.a - a);
    }
};
// Query for min;
struct ConvexHull {
    deque <Line> q;
    void add(Line nLine) {
        // need to change when a is increasing or decreasing
        while (q.size() >= 2 && q[q.size() - 1].cross(nLine) <= q[q.size() - 1].cross(q[q.size() - 2]))
            q.pop_back();
        q.push_back(nLine);
    }

    ll qry(ll x) {
        while (q.size() >= 2 && q[0].cal(x) >= q[1].cal(x))
            q.pop_front();
        return q[0].cal(x);
    }
};