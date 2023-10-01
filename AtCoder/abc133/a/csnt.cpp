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

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 2;

bool isValid(int mask1, int mask2) {
    for (int i = 0; i < 4; i++)
        if ((mask1 & (1 << i)) && (mask2 & (1 << i)))
            return 0;
    return 1;
}

bool isValid(int mask) {
    for (int i = 0; i < 3; i++)
        if (mask & (1 << i) && mask & (1 << (i + 1)))
            return 0;
    return 1;
}

void run_case() {
    int n; cin >> n;
    vector <vector <int>> f(1 << 4, vector <int> (n, 0));
    vector <vector <int>> a(4, vector <int> (n, 0));
    vector <bool> used(1 << 4, 0);

    bool allNegative = 1;
    int c = -INF;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            c = max(a[i][j], c);
            if (a[i][j] >= 0)
                allNegative = 0;
        }

    for (int m = 0; m < (1 << 4); m++)
        used[m] = isValid(m);
    // used[0] = 0;
    
    for (int m = 0; m < (1 << 4); m++) {
        for (int j = 0; j < 4; j++) {
            if (m & (1 << j) && used[m])
                f[m][0] += a[j][0];
        }
    }


    for (int c = 1; c < n; c++) {
        for (int maskCur = 0; maskCur < (1 << 4); maskCur++) {
            if (!used[maskCur])
                continue;
            int sum = 0;
            for (int j = 0; j < 4; j++) {
                if (maskCur & (1 << j))
                    sum += a[j][c];
            }
            
            for (int maskPrev = 0; maskPrev < (1 << 4); maskPrev++) {
                if (!used[maskPrev])
                    continue;
                if (isValid(maskCur, maskPrev)) {
                    // debug(sum, maskCur, maskPrev, c);
                    f[maskCur][c] = max(f[maskCur][c], f[maskPrev][c - 1] + sum);
                }
            }
        }
    }    

    int res = -INF;
    for (int mask = 0; mask < (1 << 4); mask++) 
        if (used[mask])
            res = max(res, f[mask][n - 1]);
    
    if (allNegative) {
        res = c;
    }
   
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    // for (int i = 0; i <= 10; i++) cout << f[i] << "\n";
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

