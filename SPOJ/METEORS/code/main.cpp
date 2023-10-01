#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e10 - 1;
const int MOD = 1e9 + 7;
const int MAX = 3e5 + 5;

template <typename T>
struct Fenwick {
    int n;
    vector <T> f;
    Fenwick() {};
    Fenwick(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        f.assign(_n + 5, 0);
//        for (int i = 0; i <= n; ++i) f[i] = 0;
    }
    void upd(int x, int val) {
        for (; x <= n; x += x & -x)
            f[x] += val;
    }
    T qry(int x) {
        T ans = 0;
        for (; x; x -= x & -x)
            ans += f[x];
        return ans;
    }
};

struct Meteors {
    int l, r, val;
} met[MAX];

int n, m, k;
vector <int> sta[MAX];
int req[MAX];
int lhs[MAX], rhs[MAX];
int ans[MAX];

void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x; cin >> x;
        sta[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> req[i];
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> met[i].l >> met[i].r >> met[i].val;
    }

    for (int i = 1; i <= n; ++i) {
        ans[i] = INF;
        lhs[i] = 1, rhs[i] = k;
    }

    Fenwick <ll> bit;
    while (true) {
        vector <int> que[k + 5];
        bit.init(m + 5);

        bool done = 1;
        for (int i = 1; i <= n; ++i) {
//            debug(lhs[i], rhs[i]);
            if (lhs[i] <= rhs[i]) {
                done = 0;
                int m = (lhs[i] + rhs[i]) / 2;
                que[m].push_back(i);
            }
        }
        if (done) break;

        for (int i = 1; i <= k; ++i) {
//            debug(que[i], i);
            auto [l, r, val] = met[i];
            if (l > r)
                bit.upd(1, val);
            bit.upd(l, val);
            bit.upd(r + 1, -val);

            for (const auto &x : que[i]) {
                ll cur = 0;
                for (int y : sta[x]) {
                    cur += bit.qry(y);
                    if (cur >= INF) break;
                }
//                debug(cur, req[x], i, x);
                if (cur >= req[x]) {
                    ans[x] = min(ans[x], i);
                    rhs[x] = i - 1;
                }
                else
                    lhs[x] = i + 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (ans[i] == INF) cout << "NIE\n";
        else cout << ans[i] << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
