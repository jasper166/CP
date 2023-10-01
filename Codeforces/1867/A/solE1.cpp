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
const int N = 3e3 + 5;

int ask(int x) {
    cout << "? " << x << endl;
    int y; cin >> y; return y;
}
 
void out(int x) {
    cout << "! " << x << endl;
}

void run_case() {
	int n, k; 
	cin >> n >> k;
    if (n % k) {
        int x = 0, res = 0;
	    for(int i = 1; i <= n - k; i += k) {
	        x = ask(i);
	        res ^= x;
	    }
	    int j = n - (n % k);
	    j = j + 2 - k;
	    while (j <= n + 1 - k) {
	        res ^= ask(j) ^ x; 
	        ++j;
	    }
	    out(res);
	    return;
    }
    int res = 0;
    for(int i = 1; i <= n; i += k)
    	res ^= ask(i);
    out(res);
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
