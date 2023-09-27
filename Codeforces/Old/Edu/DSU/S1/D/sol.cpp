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

int n, m, k;
struct query{
    string op;
    int u, v;
};

struct DSU{
    int n;
    vector <int> p, sz;
    DSU (int _n) : n (_n){
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        FOR(i, 1, n) p[i] = i;  
    }
    int get(int a){
        return (a == p[a]? a : p[a] = get(p[a]));
    }
    void unite(int a, int b){
        a = get(a);
        b = get(b);
        if (a != b){
            if (sz[a] < sz[b]) swap(a, b);
            sz[a] += sz[b];
            p[b] = a;
        }
    }
};




void run_case(){
    cin >> n >> m >> k;
    DSU dsu(n);
    FOR(i, 1, m){
        int u, v;
        cin >> u >> v;
    }
    vector <query> a(k + 1);
    FOR(i, 1, k){
        cin >> a[i].op >> a[i].u >> a[i].v;
    }
    vector <string> ans;
    FORD(i, k, 1){
        if (a[i].op == "cut"){
            dsu.unite(a[i].u, a[i].v);
        }
        else {
            ans.push_back(dsu.get(a[i].u) == dsu.get(a[i].v)? "YES\n" : "NO\n");
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans){
        cout << i;
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



