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
const int MAX = 1e5 + 5;

int n, m;
pii a[MAX];
void run_case() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }   
    sort(a + 1, a + 1 + n);
    priority_queue <int> q;
    int j = 1;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (; a[j].fi == i && j <= n; j++) q.push(a[j].se);
        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
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

