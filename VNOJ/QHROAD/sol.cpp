#include "bits/stdc++.h"

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
const int MAX = 2e5 + 5;

struct DSU{
    int n;
    vector <int> lab;
    DSU (int _n) : n (_n){
        lab.assign(n + 1, -1);
    }
    int get(int a){return (lab[a] < 0? a : lab[a] = get(lab[a]));}

    void unite(int a, int b){
        a = get(a);
        b = get(b);
        if (a != b){
            if (lab[a] < lab[b]) swap(a, b);
            lab[a] += lab[b];
            lab[b] = a;
        }
    }
};
struct edges{
    int u, v;
};

int n, m, q;
edges e[MAX];
int query[MAX], ans[MAX];
bool dest[MAX];
DSU dsu(MAX);

void run_case(){
    cin >> n >> m >> q;

    FOR(i, 1, m)
        cin >> e[i].u >> e[i].v;
    
    FOR(i, 1, q){
        cin >> query[i];
        dest[query[i]] = 1;
    }
    int component = n;
    
    auto process = [&](int u, int v){
        int s = dsu.get(u);
        int t = dsu.get(v);
        if (s != t){
            component--;
            dsu.unite(s, t);
        }
    };

    FOR(i, 1, m){
        if (!dest[i]){
            process(e[i].u, e[i].v);
        }
    }
    ans[q] = component;
    FORD(i, q, 1){
        int j = query[i];
        process(e[j].u, e[j].v);
        ans[i - 1] = component;
    }
    FOR(i, 1, q) cout << ans[i] << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



