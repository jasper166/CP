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
const int N = 2e2 + 5;

int n, m;
int a[N][N];
int prf[N][N];
int get(int a, int b, int A, int B) {
    return (prf[A][B] - prf[A][b - 1] - prf[a - 1][B] + prf[a - 1][b - 1]);
}
void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c; cin >> c;
            a[i][j] = (c == 'X');
            prf[i][j] = 
                prf[i - 1][j] + prf[i][j - 1] - prf[i - 1][j - 1] + a[i][j];
        }
    }
    // FOR(i, 1, n) FOR(j, 1, m) {cout << a[i][j] << " \n"[j == m];}
    int ans = 0;
    for (int c1 = 1; c1 <= m; ++c1) {
        for (int c2 = c1; c2 <= m; ++c2) {
            int last_row = -1;
            for (int r = 1; r <= n; ++r) {
                // if this row is usable
                int sum = get(r, c1, r, c2);
                bool usable = (sum == 0);
                if (usable) {
                    // use this row only
                    ans = max(ans, c2 - c1 + 1);
                    // including the last row
                    if (last_row != -1) {
                        int cur = (r - last_row + 1) * (c2 - c1 + 1);
                        ans = max(ans, cur);
                    }
                    if (last_row == -1)
                        last_row = r;
                }
                // cannot use last row anymore
                if (a[r][c1] || a[r][c2])
                    last_row = -1;
            }
        }
    }
    cout << ans << "\n";
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    // setIO("fortmoo");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
