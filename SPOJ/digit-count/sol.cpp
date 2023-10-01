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

int n, m;
vector <int> S;
string X;
ll f[12][2][2][12]; 
bool have[12];

ll cal(int pos, int smaller, int zero, int last) {
    if (pos == n)
        return 1;

    if (f[pos][smaller][zero][last] != -1)
        return f[pos][smaller][zero][last];

    ll ans = 0;
    int upper = (smaller? 9 : X[pos] - '0');
    // debug(pos, smaller, zero, last);

    for (int d = 0; d <= min(S[m], upper); d++) {
        if (!have[d] || (d == 0 && !zero))
            continue;
        if (abs(d - last) > 2 && zero == 0)
            continue;
        int next_smaller = smaller || (d < X[pos] - '0');
        if (zero) 
            ans += cal(pos + 1, next_smaller, zero && (d == 0), d);
        else
            ans += cal(pos + 1, next_smaller, 0, d);
    }

    return f[pos][smaller][zero][last] = ans;
}


ll solve(ll x) {
    X = to_string(x);
    // debug(X);
    memset(f, -1, sizeof f);
    n = X.size();
    return cal(0, 0, 1, 10);
}

void run_case() {
    cin >> m >> n;
    S.resize(m + 1);
    memset(have, 0, sizeof have);

    have[0] = 1;
    for (int i = 1; i <= m; i++) {
        cin >> S[i];
        have[S[i]] = 1;
    }
    ll x = 0;
    for (int i = 1; i <= n; i++) {
        x = x * 10 + S[m];
    }
    ll R = solve(x);
    x = 0;
    for (int i = 1; i <= n; i++) {
        x = x * 10 + S[1];
    }
    ll L = solve(x - 1);
    cout << R - L << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){
        cout << "Case " << test << ": ";
        run_case();
    }
}

