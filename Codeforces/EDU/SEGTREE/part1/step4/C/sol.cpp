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
const int MAX = 1e5 + 5;


int n, q;
int a[MAX];

struct Node {
    ll inv = 0;
    int cnt[42];
    Node () {
        inv = 0;
        memset(cnt, 0, sizeof cnt);
    }
};
struct SegTree {
    Node *f;
    int n;

    Node merge(Node l, Node r) {
        Node res = Node();
        res.inv = l.inv + r.inv;
        for (int x = 1; x <= 40; x++) {
            res.cnt[x] += (l.cnt[x] + r.cnt[x]);
        }
        for (int x = 1, s = 0; x <= 40; x++) {
            res.inv += 1LL * l.cnt[x] * s;
            s += r.cnt[x];
        }
        return res;
    }

    void build(int N) {
        f = new Node[2 * N + 1];
        for (int i = 0; i <= 2 * n; i++) f[i].inv = 0;
        n = N;
        for (int i = 0; i < n; i++) {
            f[i + n].inv = a[i];
        }
        for (int i = n - 1; i >= 1; i--) {
            f[i].inv = f[i << 1].inv + f[i << 1 | 1].inv;
            // f[i] = merge(f[i << 1], f[i << 1 | 1]);   
        }
    }

    void modify(int x, int val) {
        f[x + n].inv = 0;
        f[x + n].cnt[val] = 1;
        for (; x > 1; x >>= 1)
            f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }

    ll get(int l, int r) {
        // Node res;
        // for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        //     if (l & 1) res = merge(res, f[l++]);
        //     if (r & 1) res = merge(f[--r], res);
        // }
        // return res.inv;
        int s = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) s += f[l++].inv;
            if (r & 1) s += f[--r].inv;
        }
        return s;
    }

};


void run_case() {
    cin >> n >> q;
    // debug(n, q);
    SegTree st;
    
    for (int i = 0; i < n; i++) {
        // int x; 
        cin >> a[i];
        // st.modify(i, x);
    }
    st.build(n);
    for (int i = 0; i < n; i++) {
        cout << st.get(i, n + 1) << " \n"[i == n - 1];
    }
    
    
    // while (q--) {
    //     int cmd, x, y;
    //     cin >> cmd >> x >> y;
    //     --x;
    //     debug(cmd, x, y);
    //     if (cmd == 1) {
    //         // [x, y);
    //         cout << st.get(x, y) << "\n";
    //     }
    //     else {
    //         // a[x] = y;
    //         st.modify(x, y);
    //     }
    // }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

