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
const int MAX = 1e6 + 5;

// set <int> s;
struct DisjointSets {
    int *p, *nxt;
    int n;
    DisjointSets (int N) {
        p = new int[N + 1];
        nxt = new int[N + 1];
        this->n = N;
        // s.clear();
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            nxt[i] = i + 1;
        }
    }
    
    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    void join (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        if (u > v)
            swap(u, v);
        p[v] = u;
    }

    void joinRange (int l, int r) {
        for (int i = l; i < r; ) {
            join(i, nxt[i]);
            int j = nxt[i];
            nxt[i] = max(nxt[i], r);
            i = j;
        }
    }

    void query (int u, int v) {
        u = get(u);
        v = get(v);
        cout << (u == v? "YES\n" : "NO\n");
    }
};

int n, q;

void run_case(){
    cin >> n >> q;
    DisjointSets dsu(n);

    for (int Q = 1; Q <= q; Q++) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 1) 
            dsu.join(x, y);
        else if (cmd == 2)
            dsu.joinRange(x, y);
        else
            dsu.query(x, y);
    }
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

