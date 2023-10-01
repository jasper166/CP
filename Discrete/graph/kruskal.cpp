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
const int MAX = 1e2 + 5;

int p[MAX], rk[MAX];
int n, m;

int get (int u ) {
    return (u == p[u]? u : p[u] = get(p[u]));
}

bool unite (int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v)
        return 0;
    if (rk[v] > rk[u])
        swap(u, v);
    p[v] = u;
    if (rk[u] == rk[v])
        rk[u]++;
    return 1;
}
using T = tuple <int, int, int>;
int a[MAX][MAX];
void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        rk[i] = 0;
        p[i] = i;
    }
    vector <T> e;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            cin >> a[u][v];
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v = u; v <= n; v++) {
            if (a[u][v]) {
                e.push_back({a[u][v], u, v});
            }
        }
    }
    sort(all(e));
    vector <pii> mst; 
    int res = 0;
    for (auto [w, u, v] : e) {
        if (unite(u, v)) {
            res += w;
            mst.push_back({u, v});
        }
    }
    if ((int) mst.size() != n - 1) {
        cout << "Do thi khong lien thong\n";
        return;
    }
    for (auto [u, v] : mst) cout << u << " " << v << "\n";
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

