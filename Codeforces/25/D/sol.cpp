#include "bits/stdc++.h"
// @Jasper


using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

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
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

template <int N> struct DSU{
    
    int pa[N + 5], sz[N + 5];
    DSU(){
        for (int i = 1; i <= N; i++) 
            pa[i] = i, sz[i] = 1;
    }
    int find(int u){
        return (u == pa[u]? u : pa[u] = find(pa[u]));
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if (u != v){
            if (sz[u] < sz[v]) swap(u, v);
            pa[v] = u;
            sz[u] += sz[v];
        }
    }
};

DSU <MAX> dsu;
vector <pii> rm;
vector <int> build;
int n;

void run_case(){
    
    cin >> n;    
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        int root_sz = dsu.sz[dsu.find(u)];
        dsu.unite(u, v);
        // case that the current bridge isn't neccessary
        if (root_sz == dsu.sz[dsu.find(u)])
           rm.emplace_back(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (i == dsu.find(i))
            build.push_back(i);
    
    cout << rm.size() << "\n";
    for (int i = 0; i < (int) rm.size(); i++)
        cout << rm[i].fi << " " << rm[i].se << " " << build[i] << " " << build[i + 1] << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


