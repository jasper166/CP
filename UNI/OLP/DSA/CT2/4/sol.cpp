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
#define debug(...) 42
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 32;

int res;
vector <int> e;
int n, k;
int a[MAX];
bool used[MAX];
void func (int i, int sum) {
	if (sum == k) {
        // cout << e.size() << "\n";
        res = min(res, (int) e.size());
        return;
    }

    for (int j = i; j <= n; j++) {
        if (!used[j] && sum + a[j] <= k) {
                used[j] = 1;
                e.push_back(a[j]);
                func(j, sum + a[j]);
                e.pop_back();
                used[j] = 0;
        }
    }
}

void run_case() {
    res = INF;
    memset(used, 0, sizeof used);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a + 1, a + 1 + n);
    func(1, 0);
    cout << res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    // cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


