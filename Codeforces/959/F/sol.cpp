#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

vector <pii> qs[N];
int n, q;
int a[N];
int ans[N];
bool dp[1 << 20];

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= q; ++i) {
        int l, x; cin >> l >> x;
        qs[l].push_back({x, i});
    }
    
    vector <int> vals;
    vals.push_back(0);
    dp[0] = 1;
    int p = 1;
    for (int i = 1; i <= n; ++i) {
        if (dp[a[i]]) 
            p = (2ll * p) % MOD;
        else {
            int sz = vals.size();
            for (int j = 0; j < sz; ++j) {
                dp[vals[j] ^ a[i]] = 1;
                vals.push_back(vals[j] ^ a[i]);
            }
        }
        for (auto [x, id] : qs[i]) {
            ans[id] = (dp[x]? p : 0);
        }
    }

    for (int i = 1; i <= q; ++i) cout << ans[i] << "\n";
}
/*
    dp(i, x) : number of subsequences XOR sum = x using 1...i
    dp(i, x) = j for all x in set.
    dp(i + 1, x) = 2 * dp(i, x) (x in set)
                 = 0 (if x not in set)
    -> dp(i, x) = 2 ^ dp(k, x) if x in set, = 0 if not
*/
// XOR basis
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    // cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
