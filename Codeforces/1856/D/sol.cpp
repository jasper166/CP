#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int ask(int l, int r) {
    if (l == r) return 0;
    cout << "? " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}

int solve(int l, int r) {
    if (l == r) return l;
    int m = (l + r) / 2;
    int ql = solve(l, m);
    int qr = solve(m + 1, r);
    return (ask(ql, qr) > ask(ql, qr - 1)? ql : qr); 
}

void run_case() {
    int n; cin >> n;
    int pos = solve(1, n);
    cout << "! " << pos << endl;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){
        run_case();
    }
}


