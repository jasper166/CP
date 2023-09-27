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

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

struct BIT {
    vector <int> f;
    int N;
    BIT(int _N): N(_N), f(_N + 5) {};

    void upd(int x, int val) {
        for (; x <= N; x += x & -x) f[x] += val;
    }
    int qry(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x) ans += f[x];
        return ans;
    }
    int qry(int l, int r) {
        return (qry(r) - qry(l - 1));
    }
};

struct Query {
    int l, r, id;
    bool operator < (const Query& o) const {
        return (r < o.r);
    }
} que[MAX];

int n, q;
int ans[MAX];
int a[MAX];

void run_case() {
    cin >> n >> q;
    vector <int> b;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= q; ++i) {
        cin >> que[i].l >> que[i].r;
        que[i].id = i;
    }
    sort(que + 1, que + 1 + q);

    BIT bit(n);
    map <int, int> lastSeen;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        if (lastSeen.count(a[i]))
            bit.upd(lastSeen[a[i]], -1);
        lastSeen[a[i]] = i;
        bit.upd(i, 1);
//        auto [l, r, pos] = que[idx];
        while (j <= q && que[j].r == i) {
            ans[que[j].id] = bit.qry(que[j].l, que[j].r);
            ++j;
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in2", "r", stdin);
    #endif

    int Test = 1;
//    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
