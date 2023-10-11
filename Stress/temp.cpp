#include <bits/stdc++.h>

#define nl "\n"
#define no "NO"
#define yes "YES"
#define fi first
#define se second
#define vec vector
#define task "main"
#define _mp make_pair
#define ii pair<int, int>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define evoid(val) return void(std::cout << val)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FOD(i, b, a) for(int i = (b); i >= (a); --i)
#define unq(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

template<typename U, typename V> bool maxi(U &a, V b) {
    if (a < b) { a = b; return 1; } return 0;
}
template<typename U, typename V> bool mini(U &a, V b) {
    if (a > b) { a = b; return 1; } return 0;
}

#define int long long

const int N = (int)100 + 9;
const int mod = (int)1e9 + 7;

void prepare(); void main_code();

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    const bool MULTITEST = 0; prepare();
    int num_test = 1; if (MULTITEST) cin >> num_test;
    while (num_test--) { main_code(); }
}

const int MAX = N * (N - 1) / 2;

const long long INF = (long long)1e18;

long long dp[N][MAX + 7];

void add(long long &a, long long b) {
    a += b; if (a >= INF) a = INF;
}

void prepare() {
    // const int n = 100;
    // dp[1][0] = 1;
    // FOR(i, 1, n - 1) FOR(j, 0, MAX) if (dp[i][j]) {
    //     FOR(k, 0, i) { // so luong gia tri duoc truoc i + 1
    //         add(dp[i + 1][j + i - k], dp[i][j]);
    //     }
    // }

    dp[1][0] = 1;
    for (int i = 1; i < 100; ++i) {
        for (int j = 0; j <= MAX; ++j) {
            if (!dp[i][j]) continue;
            for (int l = 0; l <= i; ++l) {
                int n_val = i + j - l;
                dp[i + 1][n_val] = dp[i + 1][n_val] + dp[i][j];
                dp[i + 1][n_val] = min(dp[i + 1][n_val], INF);
            }
        }
    }
};

int n, m; long long k;
int cur_cnt = 0;

int a[N], f[N], d[N]; bool use[N];

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

void main_code() {
    cin >> n >> m >> k;
    FOR(i, 1, n) {
        FOR(j, 1, n) if (!use[j]) {
            a[i] = j; use[j] = 1;
            int nc = cur_cnt;
            FOR(z, 1, i - 1) {
                nc += a[z] > a[i];
            }
            long long v;
            if (nc > m) {
                v = 0;
            } else {
                v = helper(nc, i);
            }
            if (v >= k) {
                cur_cnt = nc;
                break ;
            }
            if (j == n) evoid(-1);
            k -= v; use[j] = 0;
        }
    }
    FOR(i, 1, n) cout << a[i] << ' ';
}
