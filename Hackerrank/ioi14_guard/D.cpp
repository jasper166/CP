#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 3e3 + 5;

int a[MAX][MAX], lhs[MAX], rhs[MAX], next_lhs[MAX], next_rhs[MAX];

void run_case() {
    int n; cin >> n;
    REP(i, n) {
        string s; cin >> s;
        REP(j, n) 
            a[i][j] = (s[j] == '1');
    }
    int ans = 0;
 
    REP(i, n) lhs[i] = rhs[i] = 0;
 
    REP(i, n) {
        int cur = 0;
        REP(j, n) {
            cur += lhs[j];
            if (cur & 1) 
                a[i][j] ^= 1;
            cur -= rhs[j];
            if (!a[i][j]) continue;
            ans += 1;
            int x = max(0, j - 1);
            int y = min(n - 1, j + 1);
            next_lhs[x] += 1;
            next_rhs[y] += 1;
        }
        REP(j, n) {
            int x = max(0, j - 1);
            int y = min(n - 1, j + 1);
            next_lhs[x]  += lhs[j];
            next_rhs[y]  += rhs[j];
        }
        REP(j, n) {
            lhs[j] = next_lhs[j];
            rhs[j] = next_rhs[j];
            next_lhs[j] = next_rhs[j] = 0;
        }
    }
    cout << ans << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


