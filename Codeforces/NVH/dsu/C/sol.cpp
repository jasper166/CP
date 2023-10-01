#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;


struct DisjointSets {
    int *p;
    int n;
    bool *used;
    DisjointSets (int N) {
        this->n = N;
        p = new int[2 * N + 1];
        used = new bool[2 * N + 1];
        for (int i = 1; i <= 2 * n; i++) {
            p[i] = i;
            used[i] = 0;
        }
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    bool joinRange (int l, int r) {
        bool res = 1;
        int d = get(r + 1);
        for (int i = l; i <= r; ) {
            if (used[i])
                res = 0;
            else 
                used[i] = 1;
            int j = get(i) + 1;
            p[i] = d;
            i = j;
        }
        return res;
    }

};

int n, m;
void run_case(){
    cin >> n >> m;
    vector <pii> a(m + 1);
    vector <int> c;
    for (int i = 1; i <= m; i++) {
        int u, v; 
        cin >> u >> v;
        a[i] = {u, v};
        c.push_back(u);
        c.push_back(v);
    }

    sort(all(c));
    c.resize(unique(c.begin(), c.end()) - c.begin());
    for (int i = 1; i <= m; i++) {
        a[i].fi = (int) (lower_bound(all(c), a[i].fi) - c.begin()) + 1;
        a[i].se = (int) (lower_bound(all(c), a[i].se) - c.begin()) + 1;
    }

    DisjointSets dsu(min(MAX, n + 1));
    int res = 0;
    for (int i = m; i >= 1; i--) {
        auto &[l, r] = a[i];
        res += dsu.joinRange(l, r);
    }
    cout << res << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

