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
int nxt[MAX], cnt[MAX];
// nxt: next point if jump from x;
// cnt: how many jump it takes to jump from current block to next block;
pii qry(int x) {
    pii ans = {0, 0};

    // Find the last block before leaving the row;
    while (x <= n) {
        ans.se += cnt[x];
        if (nxt[x] > n)
            ans.fi = x;
        x = nxt[x];
    }
    // Last block processing
    while (ans.fi + a[ans.fi] <= n)
        ans.fi += a[ans.fi];

    return ans;
}

void upd(int x, int val) {
    a[x] = val;
    // Processing for current block;
    for (int i = x; i >= 1 && i / BLOCK == x / BLOCK; i--) {
        int curBlock = i / BLOCK;
        int nxtBlock = (i + a[i]) / BLOCK;

        if (curBlock < nxtBlock || i + a[i] >= n) {
            nxt[i] = i + a[i];
            cnt[i] = 1;
        }
        else {
            nxt[i] = nxt[i + a[i]];
            cnt[i] = 1 + cnt[i + a[i]];
        }
    }

}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        upd(i, a[i]);
    
    while (q--) {
        int cmd, x, val; cin >> cmd;
        if (cmd) {
            cin >> x;
            pii ans = qry(x);
            cout << ans.fi << " " << ans.se << "\n";
        }
        else {
            cin >> x >> val;
            upd(x, val);
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

