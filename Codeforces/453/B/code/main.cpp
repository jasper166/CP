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
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e2 + 5;

int n;
int a[MAX];
int dp[1 << 17][MAX];
int tr[1 << 17][MAX];
int p[MAX];

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int maxSz = *max_element(a + 1, a + 1 + n);
    maxSz *= 2;
    vector <int> prime;
    vector <bool> d(maxSz + 5, 1);
    for (int i = 2; i <= sqrt(maxSz); ++i)
        if (d[i])
            for (int j = i * i; j <= maxSz; j += i)
                d[j] = 0;
    for (int i = 2; i <= maxSz; ++i)
        if (d[i])
            prime.push_back(i);

    int m = prime.size();
    for (int i = 1; i <= maxSz; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i % prime[j] == 0)
                p[i] |= (1 << j);
        }
    }
    for (int msk = 0; msk < (1 << m); msk++)
        for (int i = 0; i <= n; ++i)
            dp[msk][i] = INF;

//    debug(prime);

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int msk = 0; msk < (1 << m); msk++) {
            for (int x = 1; x <= maxSz; ++x) {
                if (p[x] & msk) continue;
                int nxt_msk = p[x] | msk;
                if (dp[nxt_msk][i] > dp[msk][i - 1] + abs(a[i] - x)) {
                    dp[nxt_msk][i] = dp[msk][i - 1] + abs(a[i] - x);
                    tr[nxt_msk][i] = x;
                }
            }
        }
    }


    int ans = INF, ans_msk = -1;
    for (int msk = 0; msk < (1 << m); ++msk) {
        if (ans > dp[msk][n]) {
            ans = dp[msk][n];
            ans_msk = msk;
        }
    }
//    debug(ans, ans_msk);
    vector <int> res;
    for (int i = n; i >= 1; --i) {
        int x = tr[ans_msk][i];
        res.push_back(x);
        ans_msk ^= p[x];
    }
    reverse(res.begin(), res.end());
    for (int x : res) cout << x << " ";
    cout << "\n";

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
