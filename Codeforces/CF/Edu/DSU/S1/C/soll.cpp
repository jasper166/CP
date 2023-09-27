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
const int MAX = 1e6 + 5;

struct DSU{
    int n;
    vector <int> p, sz, d, score;
    vector <vector <int>> adj;
    DSU(int _n) : n(_n){
        p.resize(n + 1);
        d.resize(n + 1);
        score.resize(n + 1);
        sz.assign(n + 1, 1);
        FOR(i, 1, n) p[i] = i, d[i] = score[i] = 0;
        adj = vector <vector <int>> (n + 1);
        FOR(i, 1, n){
            adj[i].push_back(i);
        }
    }

    int get(int x){
        return (p[x] == x? x : p[x] = get(p[x]));
    }
    int query(int x){
        return score[x] + d[get(x)];
    }
    void update(int u, int w){
        u = get(u);
        d[u] += w;
    }
    void unite(int a, int b){
        a = get(a); b = get(b);
        if (a != b){
            if (sz[a] < sz[b]) swap(a, b);
            for (int x : adj[b]){
                score[x] += d[b] - d[a];
                adj[a].push_back(x);
            }
            sz[a] += b;
            p[b] = a;
            d[b] = 0;
            adj[b].clear();
        }
    }

};



void run_case(){
    int n, m, v, u;
    string s;

    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--){
        cin >> s >> u;
        if (s == "join"){
            cin >> v;
            dsu.unite(u, v);
        }
        else if (s == "add"){
            cin >> v;
            dsu.update(u, v);
        }
        else {
            cout << dsu.query(u) << "\n";
        }
    }

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



