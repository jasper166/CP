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
const int MAX = 1e5 + 5;

string s;
int n;
void run_case() {
    cin >> n >> s;
    vector <int> ans(n + 5, 0);
    int c = 0;
    REP(i, n / 2)
		if (s[i] != s[n - i - 1]) c++;
    ans[c] = 1;
    int C = c << 1;
    for (int i = 0; i + C <= n; i += 2)
        ans[i + c] = 1;
    if (n % 2) {
        for(int i = 0; i + C <= n; i += 2)
            ans[i + c + 1] = 1;
    }
    FOR(i, 0, n) cout << ans[i];
    cout << "\n";
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
