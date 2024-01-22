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
const int MAX = 5e3 + 5;

int n, q;
string s;
ll f[MAX][MAX];
bool pal[MAX][MAX];

void run_case() {
    cin >> s >> q;
    int n = s.size();
    s = "$" + s;

    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            if (l == r) {
                f[l][r] = pal[l][r] = 1;
                continue;
            }
            if (l + 1 == r) {
                pal[l][r] = (s[l] == s[r]);
                f[l][r] = (s[l] == s[r])? 3 : 2;
                continue;
            }
            pal[l][r] = pal[l + 1][r - 1] & (s[l] == s[r]);
            f[l][r] = f[l + 1][r] + f[l][r - 1] - f[l + 1][r - 1] + (pal[l][r]);
        }
    }


    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        cout << f[l][r] << "\n";
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

