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
#define task "in1"
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n, q;
int a[MAX], b[MAX];
multiset <int> num, dis;

void del(int x) {
    auto p = num.lower_bound(x);
    auto lhs = prev(p); 
    auto rhs = next(p); 
    if (p != num.begin()) {
        // debug("here_1");
        dis.erase(dis.lower_bound(x - *lhs));
    }
    if (rhs != num.end()) {
        // debug("here_2", *rhs - x);
        dis.erase(dis.lower_bound(*rhs - x));
    }
    if (p != num.begin() && rhs != num.end())
        dis.insert(*rhs - *lhs);
    num.erase(p);
}

void add(int x) {
    num.insert(x);
    auto p = num.lower_bound(x);
    auto lhs = prev(p);
    auto rhs = next(p);

    if (p != num.begin())
        dis.insert(x - *lhs);
    if (rhs != num.end())
        dis.insert(*rhs - x);
    if (p != num.begin() && rhs != num.end())
        dis.erase(dis.lower_bound(*rhs - *lhs));

}

void run_case() {
    num.clear();
    dis.clear();

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i];
        num.insert(b[i]);
    }
    sort(b + 1, b + 1 + n);
    // for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i == n];
    for (int i = 1; i < n; ++i) {
        dis.insert(b[i + 1] - b[i]);
    }
    debug(num, dis);
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int j, x; cin >> j >> x;
        int ans;
        if (n == 1) {
            ans = x;
        }
        else {
            del(a[j]);
            a[j] = x;
            add(a[j]);
            ans = (*num.rbegin() + *dis.rbegin());
        }
        // debug(num, "1"); debug(dis, "1");
        
        // debug(num, "2"); debug(dis, "2");
        
        // debug(num, "3"); debug(dis, "3");
        cout << ans << " \n"[i == q];
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen(task, "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
