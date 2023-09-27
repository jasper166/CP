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
#define _GLIBCXX_DEBUG
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 5005;

int n, m, t;
vector <pii> edges[MAX];
vector < map < ll, pair<ll, ll> > > f(MAX);
// number of citys, time taken, previous city
int degree[MAX];

void run_case(){
    cin >> n >> m >> t;
    FOR(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        degree[v]++;
    }
    vector <int> topo;
    priority_queue <int, vector <int>, greater <int>> q;
    FOR(i, 1, n) 
        if (!degree[i]) 
            q.push(i);
    
    while (!q.empty()){
        int u = q.top();
        q.pop();
        topo.push_back(u);
        for (auto v : edges[u]){
            --degree[v.fi];
            if (!degree[v.fi]) 
                q.push(v.fi);
        }
    }
    reverse(all(topo));
    debug(topo);
    
    f[n][0] = {0, 0};
    // f(i, j, k, l) : from city, numbers of city need to travel, takes k time, next city is l
    for (auto node : topo){
        if (node == n) continue;
        for (auto neigh : edges[node]){
            for (auto ele : f[neigh.fi]){
                ll places = ele.fi;
                pair <ll, ll> road = ele.se;
                if (f[node].count(places + 1) == 0 || f[node][places + 1].fi > (ll) road.fi + neigh.se){
                    f[node][places + 1].fi = (ll) road.fi + neigh.se;
                    f[node][places + 1].se = neigh.fi;
                }
            }
        }
    }
    ll places = 1;
    for (auto ele : f[1]){
        if (ele.se.fi <= t) places = ele.fi; 
    }
    cout << places + 1 << "\n";
    ll u = 1;
    while (places){
        cout << u << " ";
        u = f[u][places].se;
        --places;
    }
    FOR(i, 1, n){
        cout << i << " " << f[i] << " " << f[i].fi << " "  << f[i].se << "\n";
    }
        
    cout << n << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


