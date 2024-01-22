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
const int MAX = 1e5 + 5;

int n;
ll S;
using T = tuple <int, int, ll>;
T f[1 << 24];
void run_case() {
    cin >> n >> S;
    vector <T> items;
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        sz += k;
        for (int j = 0; j < k; ++j) {
            int w; cin >> w;
            items.push_back({i, w});
        }
    }
    assert(sz <= 23);
    debug(items);
    f[0] = {1, 0, 0};
    for (int msk = 1; msk < (1 << sz); ++msk) {
        for (int j = 0; j < sz; ++j) {
            if (msk & (1 << j))
                continue;
            int nxt_msk = msk | (1 << j);
            T cur = f[msk];
            if ()
        }
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
