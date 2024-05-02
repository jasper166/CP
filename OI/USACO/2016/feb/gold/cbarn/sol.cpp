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

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;
int a[N];
void run_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int min_id = -1;
    int sum = 0, min_sum = INF;
    for (int i = 0; i < n; ++i) {
        sum += a[i] - 1;
        if (sum < min_sum) {
            min_sum = sum;
            min_id = i;
        }
    }
    // ->rotate array
    rotate(a, a + min_id + 1, a + n);
    queue <int> q;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) q.push(i);
        int lst = q.front(); q.pop();
        ans += (i - lst) * (i - lst);
    }
    cout << ans << "\n";
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    // setIO("cbarn");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


