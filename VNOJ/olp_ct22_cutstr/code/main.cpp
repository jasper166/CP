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
const int MAX = 1e4 + 5;

string s;
int n;
const int BASE = 31;
ull pw[MAX];
ull hs[MAX], rhs[MAX];
int f[1 << 14];
// min cost to reach mask;
int t;
int len[14];
int nxt[MAX][14];
// nxt(i, j) min cost to reach len(j) from pos i of s;
bool isPalin(int l, int r) {
    if (l > r) swap(l, r);
    int R = n - l + 1;
    int L = n - r + 1;
    ull H = hs[r] - hs[l - 1] * pw[r - l + 1];
    ull rH = rhs[R] - rhs[L - 1] * pw[R - L + 1];
//    debug(H, rH);
    return (H == rH);
}

void run_case() {
    cin >> s;

    n = s.size();
    string rs = s;
    reverse(rs.begin(), rs.end());
    s = "@" + s;
    rs = "@" + rs;
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * BASE;
        hs[i] = hs[i - 1] * BASE + (s[i] - 'a' + 1);
        rhs[i] = rhs[i - 1] * BASE + (rs[i] - 'a' + 1);
    }
//    debug(isPalin(3, 5));
    cin >> t;
    while (t--) {
        int k; cin >> k;
        for (int i = 0; i < k; ++i) cin >> len[i];

        for (int j = 0; j < k; ++j)
            nxt[n + 1][j] = INF;
        for (int i = n; i >= 0; --i) {
            for (int j = 0; j < k; ++j) {
                nxt[i][j] = nxt[i + 1][j];
                if (isPalin(i, i + len[j] - 1))
                    nxt[i][j] = min(nxt[i][j], i + len[j] - 1);
            }
        }

        fill(f, f + (1 << k), INF);
        f[0] = 0;
        for (int msk = 0; msk < (1 << k); msk++) {
            if (f[msk] > n)
                continue;
            for (int i = 0; i < k; ++i) {
                if (!(msk & (1 << i)))
                    f[msk | (1 << i)] = min(f[msk | (1 << i)], nxt[f[msk] + 1][i]);
            }
        }
        cout << (f[(1 << k) - 1] != INF? "YES\n" : "NO\n");
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

