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
const int BLOCK = 325;


int n, q;
int a[MAX];
multiset <int> st[BLOCK];

int qry(int l, int r, int k) {
    int L = l / BLOCK;
    int R = r / BLOCK;
    int ans = INF;

    // L block
    for (int i = l; i <= min(r, (L + 1) * BLOCK - 1); i++)
        if (a[i] >= k)
            ans = min(ans, a[i]);
    // R block
    for (int i = max(R * BLOCK, l); i <= r; i++)
        if (a[i] >= k)
            ans = min(ans, a[i]);

    for (int i = L + 1; i < R; i++) {
        auto iter = st[i].lower_bound(k);
        if (iter != st[i].end())
            ans = min(ans, *iter);
    }

    if (ans == INF) ans = -1;
    return ans;
}

void upd(int x, int val) {
    int X = x / BLOCK;
    st[X].erase(st[X].lower_bound(a[x]));
    a[x] = val;
    st[X].insert(a[x]);
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        st[i / BLOCK].insert(a[i]);

    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x, val;
            cin >> x >> val;
            upd(x, val);
        }
        else {
            int l, r, k;
            cin >> l >> r >> k;
            int ans = qry(l, r, k);
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

