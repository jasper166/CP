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

int tr[MAX * 30][2];
int cnt = 0;

void insert(int x) {
    int pos = 0;
//    debug(x);
    for (int j = 30; j >= 0; --j) {
        int c = (x >> j) & 1;
//        debug(c, j);
        if (!tr[pos][c])
            tr[pos][c] = ++cnt;
        pos = tr[pos][c];
    }
}

int cal(int i, int pos) {
    if (i == -1)
        return 0;
    if (!tr[pos][0])
        return cal(i - 1, tr[pos][1]);
    else if (!tr[pos][1])
        return cal(i - 1, tr[pos][0]);
    else
        return (1 << i) + min(cal(i - 1, tr[pos][0]), cal(i - 1, tr[pos][1]));
}

int n;
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        insert(x);
    }
    int ans = cal(30, 0);
    cout << ans << "\n";
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
