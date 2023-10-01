struct CHT {
    struct Line {
        ll a, b;
        Line (ll _a = 0, ll _b = 0) { a = _a; b = _b; };
        ll cal(ll x) { return a * x + b; }
        long double cross(Line o) { return (long double) (b - o.b) / (long double) (o.a - a); }
    };

    deque <Line> q;
    /*
        Decreasing slope;
        add: >= 
	Increasing slope;
	add: <=
    */
    void add(ll a, ll b) {
        Line nLine = Line(a, b);
        while (q.size() >= 2 && q[0].cross(nLine) >= q[0].cross(q[1]))
            q.pop_front();
        q.push_front(nLine);
    }

    ll qry(ll x) {
        int l = 0, r = q.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (q[m].cal(x) < q[m + 1].cal(x))
                l = m + 1;
            else
                r = m;
        }
        return q[l].cal(x);
    }

};