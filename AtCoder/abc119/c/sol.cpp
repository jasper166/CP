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

int n, A, B, C;
int a[12];
int ans;


void dfs(int i, int x, int y, int z, int cost) {

    if (i == n) {
        if (x == 0 || y == 0 || z == 0)
            return;
        int cur = cost + abs(A- x) + abs(B - y) + abs(C - z) - 30;
        ans = min(cur, ans);
        return;
    }

    dfs(i + 1, x, y, z, cost);
    dfs(i + 1, x + a[i], y, z, cost + 10);
    dfs(i + 1, x, y + a[i], z, cost + 10);
    dfs(i + 1, x, y, z + a[i], cost + 10);
    return;
} 

void run_case() {
    cin >> n >> A >> B >> C;
    for (int i = 0; i < n; i++) cin >> a[i];
    ans = INF;
    dfs(0, 0, 0, 0, 0);
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

/*
    Observe that n <= 8:
    Firstly we have to find cost of Composition as Extension or Shortening 
    can be calculated later
    So there are 4 cases of using current bamboo a(i) to consider:
    1. not use;
    2. use to form A;
    3. use to form B;
    4. use to form C;
    As we reach the bottom -> have to take off 30 as there's no cost at all
    Also if any of constructed bamboo is 0 then current branch is invalid
    Why "30"?:
    + As x, y, z > 0 so each of x, y, z is used at least one time 3rd spell 
    -> notice that we count each x, y, z is one time more than actual cost
    for example, n bamboos we can only use n - 1 times of 3rd spell to merge them

    Using backtracking to prune all possibilities.
    O(4^n);
    -> other solution is dp bitmask???
*/
