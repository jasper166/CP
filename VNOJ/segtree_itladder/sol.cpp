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

// #define int long long 
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, q;
/*
    lazy1 = i*A;
    lazy2 = B-L*A;
*/

int inv2 = 500000004;

struct Data {
    int L, A, B;
};

struct SegTree {
    int *f, *lazy1, *lazy2;

    void init (int N) {
        f = new int[N << 2 | 1];
        lazy1 = new int[N << 2 | 1];
        lazy2 = new int[N << 2 | 1];

        for (int i = 1; i <= N << 2; i++) {
            lazy1[i] = lazy2[i] = f[i] = 0;
        }
    }

    int add(ll x, ll y) {  
        ll res = (x + y) % MOD;
        return (int) res % MOD;
    }

    int cal(int l, int r, int X, int t) {
        int res = 0;
        if (t == 1){
            int range = (((1LL * (r + l) * (r - l + 1) / 2) % MOD) % MOD * 1LL * X) % MOD;
            res = add(res, range);
        }
        else
            res = add(res, (1LL * X % MOD * 1LL * (r - l + 1) % MOD) % MOD);
        return res;
    }


    void push(int x, int l, int r){
        if (!lazy1[x] && !lazy2[x]) 
            return;
        int m = (l + r) >> 1;
        f[x << 1] = add(f[x << 1], cal(l, m, lazy1[x], 1));
        f[x << 1] = add(f[x << 1], cal(l, m, lazy2[x], 2));

        f[x << 1 | 1] = add(f[x << 1 | 1], cal(m + 1, r, lazy1[x], 1));
        f[x << 1 | 1] = add(f[x << 1 | 1], cal(m + 1, r, lazy2[x], 2));

        lazy1[x << 1] = add(lazy1[x << 1], lazy1[x]);
        lazy1[x << 1 | 1] = add(lazy1[x << 1 | 1], lazy1[x]);

        lazy2[x << 1] = add(lazy2[x << 1], lazy2[x]);
        lazy2[x << 1 | 1] = add(lazy2[x << 1 | 1], lazy2[x]);

        lazy1[x] = lazy2[x] = 0;
    }

    void modify(int x, int l, int r, int u, int v, Data& val) {
        if (l > v || r < u)
            return;
        
        if (u <= l && r <= v) {
            auto [L, A, B] = val;
            f[x] = (f[x] + cal(l, r, A, 1)) % MOD;
            f[x] = (f[x] + cal(l, r, (B - (L * A) % MOD + MOD) % MOD, 2)) % MOD;
            lazy1[x] = add(lazy1[x], A);
            lazy2[x] = add(lazy2[x], (B - (L * A) % MOD + MOD) % MOD);
            return;
        }
        
        int m = (l + r) >> 1;
        push(x, l, r);
        modify(x << 1, l, m, u, v, val);
        modify(x << 1 | 1, m + 1, r, u, v, val);
        f[x] = add(f[x << 1], f[x << 1 | 1]);
    }

    int query(int x, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0;
        if (u <= l && r <= v)
            return f[x];
        push(x, l, r);
        int m = (l + r) >> 1;
        int sl = query(x << 1, l, m, u, v);
        int sr = query(x << 1 | 1, m + 1, r, u, v);
        return add(sl, sr);
    }

} st;

void run_case() {
    cin >> n >> q;
    st.init(n);
    while (q--) {
        int L, R, A, B;
        int cmd; cin >> cmd;
        if (cmd == 1) {
            cin >> L >> R >> A >> B;
            // debug(L, R, A, B);
            Data val = {L, A, B};
            st.modify(1, 1, n, L, R, val);
        }
        else {
            cin >> L >> R;
            // debug(L, R);
            cout << st.query(1, 1, n, L, R) << "\n";
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

