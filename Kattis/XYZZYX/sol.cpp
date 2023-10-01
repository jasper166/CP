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
const int MAX = 105;

bool ok;

inline void fk() {    
    cout <<(ok? "winnable\n" :  "hopeless\n");
}
int n;
using T = tuple <int, int, int>;
vector <T> edges;
int d[MAX], p[MAX];
int g[MAX];
void run_case(){
   while (cin >> n){
    if (n == -1) return;
    edges.clear();
    ok = 1;
    FOR(u, 1, n){
        int w, m;
        cin >> w >> m;
        d[u] = w;
        FOR(i, 1, m){
            int v; cin >> v;
            edges.emplace_back(u, v, w);
        }
    }
    for (auto &[u, v, w] : edges) w = d[v];

    FOR(i, 1, n) d[i] = INF, p[i] = -1;
    d[1] = 100;
    FOR(i, 1, n - 1){
        for (auto [u, v, w] : edges){
            if (d[u] != INF && d[u] + w < d[v]){
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }
    FOR(i, 1, n - 1){
        for (auto [u, v, w] : edges){
            if (d[u] != INF && d[u] + w > d[v]){
                d[v] = INF;
                p[v] = u;
            }
        }
    }
    vector <int> trace;
    int u = n;
    if (p[u] == -1) ok = 0;
    while (u != -1){
        if (d[u] <= 0 && u != n) ok = 0;
        trace.push_back(u);
        u = p[u];
    }
    
 FOR(i, 1, n) cout << d[i] << " "[i == n];
//    cout << ok << "\n";
//    fk();
    cout << (ok? "winnable" : "hopeless") << "\n";
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

