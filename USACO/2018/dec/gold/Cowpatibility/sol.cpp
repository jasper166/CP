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
const int MAX = 5e4 + 5;

int n;
map <array <int, 5>, int> f;

ll C2(ll x) {
    return 1ll * x * (x - 1) / 2;
}

int sz(array <int, 5> x) {
    int cnt = 0;
    for (int i = 0; i < 5; i++)
        cnt += (x[i] != 0);
    return cnt;
}
void run_case() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int a[5];
        for (int j = 0; j < 5; j++) 
            cin >> a[j];
        sort(a, a + 5);
        for (int msk = 1; msk < (1 << 5); msk++) {
            array <int, 5> val = {0, 0, 0, 0, 0};
            int k = 0;
            for (int j = 0; j < 5; j++) 
                if (msk & (1 << j))
                    val[k++] = (a[j]);
            f[val]++;
        }
    }

    ll total = C2(n);
    ll exl = 0;

    // debug(f);
    for (auto [x, c] : f) {
        // debug(x.fi, x.se, c);
        if (c < 2)
            continue;
        if (sz(x) & 1)
            exl += C2(c);
        else
            exl -= C2(c);
    }
    // debug(total, exl);
    cout << total - exl << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

