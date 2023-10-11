#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define           fi    first
#define           se    second
#define           f     first
#define           s     second
#define           pb    push_back
#define           ep    emplace
#define           eb    emplace_back
#define           lb    lower_bound
#define           ub    upper_bound
#define       all(x)    x.begin(), x.end()
#define      rall(x)    x.rbegin(), x.rend()
#define   uniquev(v)    sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define     mem(f,x)    memset(f , x , sizeof(f))
#define        sz(x)    (int)(x).size()
#define  __lcm(a, b)    (1ll * ((a) / __gcd((a), (b))) * (b))
#define          mxx    *max_element
#define          mnn    *min_element
#define    cntbit(x)    __builtin_popcountll(x)

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e2 + 5;

int dp[N][N * N];
int n, m, k;
int val;
int ans[N], f[N];
bool used[N];


int helper(int x, int id) {
    for (int i = n; i >= 1; --i) {
        f[i] = f[i + 1];
        f[i] += use[i + 1];
        if (use[i]) continue;
        x += f[i];
    }
    int ret;
    if (x > m) 
        ret = 0;
    else if (id == n) 
        ret = (x == m);
    else {
        int n_id = n - id;
        int n_x = m - x;
        ret = dp[n_id][n_x];
    }
    return ret;
}

void run_case() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (used[j]) continue;
            ans[i] = j;
            used[j] = 1;
            int n_val = val;
            for (int l = 1; l < i; ++l) 
                if (ans[i] < ans[l])
                    ++n_val;
            int diff = (n_val <= m)? helper(n_val, i) : 0;
            if (diff >= k) {
                val = n_val;
                break;
            }
            if (j != n) {
                used[j] = 0;
                k -= diff; 
            }
            else {
                cout << "-1\n";
                return;
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    

    dp[1][0] = 1;
    for (int i = 1; i < 100; ++i) {
        for (int j = 0; j < N * N; ++j) {
            if (!dp[i][j]) continue;
            for (int l = 0; l <= i; ++l) {
                int n_val = i + j - l;
                dp[i + 1][n_val] = dp[i + 1][n_val] + dp[i][j];
                dp[i + 1][n_val] = min(dp[i + 1][n_val], INF);
            }
        }
    }

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
