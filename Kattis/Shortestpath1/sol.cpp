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
const int MAX = 1e4 + 5;


int n, m, q, s;
vector <pii> edges[MAX];
int d[MAX];


void run_case(){
	
    while (cin >> n >> m >> q >> s){
        if (!n && !m && !q && !s) break;
        REP(i, MAX) edges[i].clear();
        FOR(i, 1, m){
            int x, y, w;
            cin >> x >> y >> w;
            edges[x].emplace_back(y, w);
        }
        FOR(i, 0, n) d[i] = INF;
        d[s] = 0;
        priority_queue<pii, vector <pii>, greater <pii>> pq;
        pq.push({0, s});

        while (!pq.empty()){
            int u = pq.top().se, du = pq.top().fi;
            pq.pop();
            if (du != d[u]) continue;
            for (auto E : edges[u]){
                int v = E.fi, w= E.se;
                if (d[u] + w < d[v]){
                    d[v] = d[u] + w;
                    pq.push({d[v], v});
                }
            }
        }
        while (q--){
            int x; cin >> x;
            if (d[x] == INF) cout << "Impossible\n";
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

