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
const int N = 50 + 5;

int save[N], a[N][N], del[N];
int n; 
void run_case() {
    cin >> n;
    
    FOR(i, 1, n) {
        FOR(j, 1, 50) a[i][j] = 0;
        int k; cin >> k;
        REP(j, k) {
            int x; cin >> x;
            a[i][x] = 1;
            del[x] |= 1;
        }
    }
    int res = 0;
    FOR(i, 1, 50) {
    	if (!del[i]) continue;
    	FOR(k, 1, 50) save[k] = 0;
        FOR(j, 1, n) {
        	if (a[j][i]) continue;
            FOR(k, 1, 50) save[k] |= a[j][k];
        }
        int cur = accumulate(save + 1, save + 1 + 50, 0);
        res = max(res, cur);
    }
    FOR(k, 1, 50) del[k] = 0;
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
