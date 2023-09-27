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
const int MAX = 1e6 + 5;


void run_case() {
    string s; cin >> s;
    int n = s.size();
    s = "$" + s;
    vector <int> f(n + 5, 0);
    for (int i = 1; i <= n; i++)
        if (s[i] == '<')
            f[i + 1] = max(f[i + 1], f[i] + 1);
    for (int i = n; i >= 1; i--)
        if (s[i] == '>')
            f[i] = max(f[i], f[i + 1] + 1);
    ll res = accumulate(all(f), 0ll);
    cout << res << "\n";
    // debug(f);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
