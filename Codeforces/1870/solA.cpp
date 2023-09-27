#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
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
#define int long long
using ll = long long;
using pii = pair < int, int >;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, k, x;
void run_case() {
	cin >> n >> k >> x;
	if (k > n) {
		cout << "-1\n";
		return;
	}
    vector <int> a(n);
    REP(i, k) a[i] = i;
    FOR(i, k, n - 1) a[i] = (x == k ? k - 1 : x);
    ll res = 0;
    FOR(i, 0, n - 1) 
    	if (a[i] > x) {
    		cout << "-1\n";
			return;
    	}
    else 
    	res += a[i];
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
