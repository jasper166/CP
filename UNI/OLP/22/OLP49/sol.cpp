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

#ifdef LOCAL
#include "debug.h"
#define TASK "OLP49"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int pa[MAX], sz[MAX];
int q;

void preprocess(){
    for (int i = 0; i < MAX; i++)
        pa[i] = i, sz[i] = 1;
}

int find(int u){
    return (u == pa[u]? u : pa[u] = find(pa[u]));
}

bool is_united(int u, int v){
    return (find(u) == find(v));
}

void unite(int u, int v){
    u = find(u);
    v = find(v);
    if (u != v){
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        pa[v] = u;
    }
}


void run_case(){

    preprocess();
    cin >> q;
    while (q--){
        int u, v, ask;
        cin >> u >> v >> ask;
        if (ask == 1)
            unite(u, v);
        else 
            cout << (int) is_united(u, v) << "\n";
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

