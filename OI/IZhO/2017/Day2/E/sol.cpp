#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
 
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 2505;

int a[N][N], lt[N][N], rt[N][N];
int w[N];

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif
 
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }
    }
 
    // for (int i = 1; i <= n; ++i) 
    //     for (int j = 1; j <= m; ++j)
    //         cout << a[i][j] << " \n"[j == m]; 
 
    //sub1: shortest consecutive 1ss
    if (n == 1 || m == 1) {
        if (n == 1) {
            int ans = 1e9;
            for (int i = 1; i <= m; ++i) {
                if (a[1][i] == 0) continue;
                int cur = 0;
                while (i <= m && a[1][i]) { 
                    ++cur;
                    ++i;
                }
                ans = min(ans, cur);
            }
            cout << ans << "\n";
            return 0;
        }
        if (m == 1) {
            int ans = 1e9;
            for (int i = 1; i <= n; ++i) {
                if (a[i][1] == 0) continue;
                int cur = 0;
                while (i <= n && a[i][1]) { 
                    ++cur;
                    ++i;
                }
                ans = min(ans, cur);
            }
            cout << ans << "\n";
            return 0;
        }
    }
 
    if (n <= 100 && m <= 100) {
        vector <vector <int>> prf(n + 5, vector <int> (m + 5, 0));
        int earth = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                earth += (a[i][j] == 0);
                prf[i][j] = prf[i][j - 1] + prf[i - 1][j] - prf[i - 1][j - 1] + a[i][j];
            }
        }
 
        int ans = 0;
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= m; ++y) {
                if (x * y <= ans) continue;
 
                // prf(l)++, prf(r + 1)--;
                vector <vector <int>> dmg(n + 2, vector <int> (m + 2, 0));
 
                for (int i = 1; i + x - 1 <= n; ++i) {
                    for (int j = 1; j + y - 1 <= m; ++j) {
                        int I = i + x - 1, J = j + y - 1;
                        if (prf[I][J] + prf[i - 1][j - 1] - prf[I][j - 1] - prf[i - 1][J] == x * y) {
                            dmg[i][j] += 1;
                            dmg[I + 1][j] -= 1;
                            dmg[i][J + 1] -= 1;
                            dmg[I + 1][J + 1] += 1;
                        }
                    }
                }
 
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= m; ++j)
                        dmg[i][j] += dmg[i - 1][j] + dmg[i][j - 1] - dmg[i - 1][j - 1];
 
                bool valid = 1;
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= m; ++j) {
                        if (a[i][j] && !dmg[i][j])
                            valid = 0;
                    }
                }
                if (valid) ans = max(ans, x * y);
            }
        }
 
        cout << ans << "\n";
        return 0;
    }
    
 
    for (int i = 1; i <= n; ++i) w[i] = m;
    // two pointer to optimize
    int min_h = 1e9;// minimum vertical strip of 1s;
 
    for (int _i = 0; _i <= 1; _i++) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                lt[i][j] = a[i][j]? (lt[i][j - 1] + 1) : 0;
 
            for (int j = m; j >= 1; --j)
                rt[i][j] = a[i][j]? (rt[i][j + 1] + 1) : 0;
 
            for (int j = 1; j <= m; ++j)
                if (a[i][j]) w[1] = min(w[1], rt[i][j] + lt[i][j] - 1);
        }
        // find feasible height
        for (int j = 1; j <= m; ++j) {
            int k = 0; // length of consecutive 1s of current column
            int l = 1e9, r = 1e9;
            for (int i = 1; i <= n; ++i) {
                if (a[i][j]) {
                    ++k;
                    l = min(l, lt[i][j]);
                    r = min(r, rt[i][j]);
                    w[k] = min(w[k], r + l - 1);
                }
                else {
                    if (k) min_h = min(min_h, k);
                    l = r = 1e9;
                    k = 0;
                }
            }
        }
 
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; j <= m; ++j)
                swap(a[i][j], a[n - i + 1][j]);
        }
 
    }
 
    int ans = 0;
    for (int h = 1; h <= min(min_h, n); ++h) {
        ans = max(ans, w[h] * h);
        w[h + 1] = min(w[h + 1], w[h]); // width is bounded by the minimum horizontal strip 
    }
 
    cout << ans << "\n";
}