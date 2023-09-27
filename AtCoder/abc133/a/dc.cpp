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
const int MAX = 1e5 + 5;

int d[] = {0, 2, 3, 5, 7};
void run_case() {
    int n;
    cin >> n;
    set <string> a;
    REP (i, n) {
        string x;
        cin >> x;
        a.insert(x);
    }
    string t;   cin >> t;
    a.erase(t);
    vector <string> p;
    for (string x : a) {
        p.push_back(x);
    }
    debug(p.size());
    sort(all(p));
    do {
        for (string x : p) cout << x << " ";
        cout << t << "\n";
    } while (next_permutation(all(p)));
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    // cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

