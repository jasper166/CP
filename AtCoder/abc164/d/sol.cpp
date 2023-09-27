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
const int MOD = 2019;
const int MAX = 2e5 + 5;

ll f[2][MOD];

void run_case() {
    string s; cin >> s;
    
    f[0][(s[0] - '0') % MOD] = 1; 
    ll ans = 0;
    for (int i = 1; i < s.size(); i++) {
        int d = s[i] - '0';
        for (int j = 0; j < MOD; j++) 
            f[1][j] = 0;
        for (int j = 0; j < MOD; j++)
            f[1][(j * 10 + d) % MOD] += f[0][j];
        
        f[1][d]++;
        ans += f[1][0];
        swap(f[0], f[1]);
    }
    cout << ans << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

