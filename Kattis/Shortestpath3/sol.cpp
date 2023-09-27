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
const int MAX = 1005;

int n, m, q, s;
using T = tuple < int, int, int >;
vector <T> edges;
int d[MAX];


void run_case(){
   
    while (cin >> n >> m >> q >> s){
    if (!n && !m  && !q && !s) return;
    edges.clear();
    FOR(i, 1, m){
        int x, y, w;
        cin >> x >> y >> w;
        edges.emplace_back(x, y, w);
    }
    FOR(i, 0, n) d[i] = INF;
    d[s] = 0;
    FOR(i, 1, n - 1){
        for (auto [u, v, w] : edges){
            if (d[u] == INF) continue;
            ckmin(d[v], d[u] + w);
        }
    }
	
    FOR(i, 1, n - 1){
        for (auto [u, v, w] : edges){
            if (d[u] != INF && d[u] + w < d[v]){
                d[v] = -INF;
            }
        }
    }
    while (q--){
        int x; cin >> x;
        if (d[x] == INF) cout << "Impossible\n";
        else if (d[x] == -INF) cout << "-Infinity\n";
        else cout << d[x] << "\n";
    }
    cout << "\n";
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

