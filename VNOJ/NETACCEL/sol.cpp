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
const int MAX = 1e3 + 5;

int n, m, k;
vector <pii> adj[MAX];
double d[12][MAX];
using T = tuple <double, int, int>;

void run_case(){
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    
    for (int i = 0; i <= k; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = INF;

    d[0][1] = 0.00;
    priority_queue <T, vector <T>, greater <T>> q;
    q.emplace(0.00, 1, 0);

    while (!q.empty()){
        auto [du, u, i] = q.top();
        q.pop();
        if (du > d[i][u])
            continue;
        for (auto [w, v] : adj[u]){
            for (int j = 0; i + j <= k; j++){
                double fw = (double) w / pow(2, j);
                debug(fw);
                if (d[i][u] + fw < d[i + j][v]){
                    d[i + j][v] = d[i][u] + fw;
                    q.emplace(d[i + j][v], v, i + j);
                }
            }
        }
    }
    cout << fixed << setprecision(2) << d[k][n] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

