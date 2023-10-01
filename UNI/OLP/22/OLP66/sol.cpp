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
#define TASK "OLP66"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n, m;
using T = pair <ll, int>;
vector <T> adj[MAX];
ll d[MAX]; 
void run_case(){
    cin >> n >> m;
    memset(d, 0x3f3f3f3f, sizeof(d));
    for (int i = 1; i <= m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    d[1] = 0;
    priority_queue <T, vector <T>, greater <T> > q;
    q.push({0, 1});
    ll cnt = 1;
    ll ans = LINF;
    while (!q.empty()){
        auto [du, u] = q.top();
        q.pop();
        if (d[u] != du) continue;
        for (auto [w, v] : adj[u]){
            if (d[u] + w <= d[v]){
                d[v] = d[u] + w;
                if (v == n){
                    if (d[v] < ans){
                        ans = d[v];
                        cnt = 1;
                    }
                    else if (d[v] == ans) cnt++;
                }
                q.push({d[v], v});
            }
        }
    }
    cout << ans << " " << cnt << "\n";
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




