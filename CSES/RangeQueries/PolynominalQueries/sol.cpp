#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n, q;
int a[MAX];

struct SegmentTree {
    ll f[MAX << 2];
    ll lz1[MAX << 2], lz2[MAX << 2];
    // lz1: i, lz2: (1 - L);
    void pull(int x) {
        f[x] = f[x << 1] + f[x << 1 | 1];
    }


    ll cal(int l, int r, int type, ll X) {
        if (type == 1) {
            return (1ll * X * (r + l) * (r - l + 1) / 2);
        }
        else 
            return (1ll * X * (r - l + 1));
    }

    void push(int x, int l, int r) {
        if (lz1[x] || lz2[x]) {
            int m = (l + r) / 2;
            f[x << 1] += cal(l, m, 1, lz1[x]);
            f[x << 1] += cal(l, m, 2, lz2[x]);

            f[x << 1 | 1] += cal(m + 1, r, 1, lz1[x]);
            f[x << 1 | 1] += cal(m + 1, r, 2, lz2[x]);

            lz1[x << 1] += lz1[x];
            lz1[x << 1 | 1] += lz1[x];

            lz2[x << 1] += lz2[x];
            lz2[x << 1 | 1] += lz2[x];

            lz1[x] = lz2[x] = 0;
        }
    }

    void build(int x, int l, int r) {
        if (l == r) {
            f[x] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(x << 1, l, m);
        build(x << 1 | 1, m + 1, r);
        pull(x);
    }

    void update(int x, int l, int r, int u, int v, ll L) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            f[x] += cal(l, r, 1, 1);
            f[x] += cal(l, r, 2, (1 - L));
            lz1[x] += 1;
            lz2[x] += (1 - L);
            return;
        }   
        push(x, l, r);
        int m = (l + r) / 2;
        update(x << 1, l, m, u, v, L);
        update(x << 1 | 1, m + 1, r, u, v, L);
        pull(x);
    }

    ll query(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0;
        if (u <= l && r <= v)
            return f[x];
        push(x, l, r);
        int m = (l + r) / 2;
        ll sl = query(x << 1, l, m, u, v);
        ll sr = query(x << 1 | 1, m + 1, r, u, v);
        return (sl + sr);
    }

} seg;


/*
    a(l) + 1 a(l + 1) + 2 + .. + -> sum(a(i) + (i - L + 1)) (l <= i <= r);
    sum (a(i)) + sum(i) + sum(1 - L);
<F5>*/

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    seg.build(1, 1, n);

    while (q--) {
        int cmd, l, r;
        cin >> cmd >> l >> r;
        if (cmd == 1) {
            seg.update(1, 1, n, l, r, l);
        }
        else {
            ll ans = seg.query(1, 1, n, l, r);
            cout << ans << "\n";
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

