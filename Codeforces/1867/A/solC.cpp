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

#define int long long
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int a[N];
int n;
int ask(int u) {
    cout << u << endl;
    int x; cin >> x;
    return x;
}

void run_case() {
	cin >> n;
    FOR(i, 1, n) cin >> a[i];
    set <int> S;
    REP(i, 3 * n + 10) S.insert(i);
    FOR(i, 1, n) 
    	if (S.find(a[i]) != S.end()) 
    		S.erase(a[i]);
    int x = *S.begin();
    int inp = ask(x);
    while (inp >= 0) {
        S.insert(inp);
        x = *S.begin(); 
        inp = ask(x);
    }
}

signed main() {
    // cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
