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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e2 + 5;
const int K = 1e5 + 5;

int k, n, m;
int d[N][K];

struct edge{
    int x, w, c;
    edge (int x, int w, int c) : x(x), w(w), c(c) {};
    bool operator < (const edge& a) const{
        return this->w > a.w;
    }
};
vector <edge> adj[N];

void run_case(){
    for (int i = 1; i <= n; i++)  adj[i].clear();    
    memset(d, 0x3f3f, sizeof d);

    cin >> k >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        adj[u].push_back(edge(v, w, c));
    }
 
    d[1][0] = 0;
    priority_queue <edge> q;
    q.push(edge(1, 0, 0));
    // u, w, c
    while (!q.empty()){
        auto [u, du, cu] = q.top();
        q.pop();

        if (d[u][cu] > du)
            continue;
        if (u == n){
            cout << du << "\n";
            return;
        }
        for (auto [v, w, c] : adj[u]){
            if (cu + c <= k && d[u][cu] + w < d[v][cu + c]){
                int cv = cu + c;
                d[v][cv] = d[u][cu] + w;
                q.push(edge(v, d[v][cv], cv));
            }
        }
    }
    cout << "-1\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

