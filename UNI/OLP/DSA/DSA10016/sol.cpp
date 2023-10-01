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

struct DisjointSets {
    int *p, *sz;
    int n;
    void init (int N) {
        this->n = N;
        p = new int[N + 1];
        sz = new int[N + 1];
        for (int i = 1; i <= N; i++){
            p[i] = i;
            sz[i] = 1;
        }
    }

    int get (int u) {
        return (u == p[u]? u : p[u] = get(p[u]));
    }

    bool same_set (int u, int v) {
        return (get(u) == get(v));
    }

    void unite (int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        if (sz[v] > sz[u])
            swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
    }
};

struct Point {
    double x, y;
} a[MAX];

int n;
void run_case(){
    cin >> n;
    DisjointSets dsu;
    dsu.init(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    vector <tuple <double, int, int>> edge;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            double d = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
            edge.emplace_back(d, i, j);
        }
    }
    sort(all(edge));
    double res = 0;
    for (auto [cost, u, v] : edge){
        if (!dsu.same_set(u, v)){
            res += cost;
            dsu.unite(u, v);
        }
    }
    cout << fixed << setprecision(6) << res << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

