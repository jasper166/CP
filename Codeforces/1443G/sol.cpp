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

int n, m, k;
vector <pii> edges[MAX];
vector <pii> pa;
vector <int> d[MAX];
// minimum cost (shortest path) to i, (j = 1 : make one road zero and j = 0 : havent make one road zero);
// -> answer would be dp[n][1];
//
// on the path from A to B: 
// consider cases:
// 1. Make one road in [A, B] to 0
// replace (u, v) by 0 => cost = min(d[a][u] + d[v][b], d[a][v] + d[u][b]);
// 2. Not make any road of [A, B] to 0 -> cost = d[a][b];

void dijkstra(int s){
    d[s].resize(n + 1);
    FOR(i, 1, n) d[s][i] = INF;
    d[s][s] = 0;
    priority_queue <pii, vector <pii>, greater <pii>> pq;
    pq.push({0, s});
    while (!pq.empty()){
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        if (du != d[s][u]) continue;
        for (auto E : edges[u]){
            int v = E.fi;
            int w = E.se;
            if (d[s][u] + w < d[s][v]){
                d[s][v] = d[s][u] + w;
                pq.push({d[s][v], v});
            }
        }
    }
}


void run_case(){
	
    cin >> n >> m >> k;
    FOR(i, 1, m){
        int x, y, w;
        cin >> x >> y >> w;
        edges[x].emplace_back(y, w);
        edges[y].emplace_back(x, w);
    }
    FOR(i, 1, n){
        dijkstra(i);
    }
    int ans = INF;
    while (k--){
        int a, b;
        cin >> a >> b;
        pa.emplace_back(a, b);
    }
    FOR(u, 1, n){
        for (auto E : edges[u]){
            int v = E.fi;
            int cur = 0;
            for (auto [a, b] : pa){
                cur += min({d[a][b], d[a][u] + d[v][b], d[a][v] + d[u][b]});
            }
            ckmin(ans, cur);
        }
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter

