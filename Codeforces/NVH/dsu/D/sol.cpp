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
const int MAX = 3e5 + 5;

struct DisjointSets {
    int *res, *nxt;
    int n;
    DisjointSets (int n) {
        this->n = n;
        res = new int[n + 5];
        nxt = new int[n + 5];
        for (int i = 1; i <= n + 1; i++) {
            res[i] = nxt[i] = 0;
        }
    }

    int get (int u) {
        return (nxt[u] == 0 ? u : nxt[u] = get(nxt[u]));
    }

    void update (int l, int r, int x) {
        int dest = get(r + 1);
        for (; l <= r; ) {
            int nl = get(l);
            if (nl > r)
                break;
            nxt[nl] = (nl <= x) ? x : dest;
            if (nl != x)
                res[nl] = x;
            l = nl + 1;
        }
        nxt[x] = 0;
    }
};


using T = tuple <int, int, int>;
T query[MAX];

int n, m;
void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, val;
        cin >> l >> r >> val;
        query[i] = {l, r, val};
    }
    DisjointSets dsu(n);
    // sort(query + 1, query + 1 + m);
    for (int i = 1; i <= m; i++) {
        auto &[l, r, x] = query[i];
        debug(l, r, x);
        dsu.update(l, r, x);
    }
    for (int i = 1; i <= n; i++) cout << dsu.res[i] << " \n"[i == n];
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

