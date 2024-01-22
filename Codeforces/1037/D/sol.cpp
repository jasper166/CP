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
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n, p[MAX];
vector <int> adj[MAX];
bool vis[MAX];

void run_case(){
    cin >> n;
    FOR(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> input, bfs;
    for (int i = 1; i <= n; i++){
        int u; cin >> u;
        p[u] = i;
        input.push_back(u);
    }
    for (int i = 1; i <= n; i++){
        sort(all(adj[i]), [](const int x, const int y){
            return p[x] < p[y];
                });
    }
    queue <int> q;
    q.push(1);
    vis[1] = 1;
    bfs.push_back(1);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (!vis[v]){
                bfs.push_back(v);
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    debug(input);
    debug(bfs);
    for (int i = 0; i < n; i++) if (bfs[i] != input[i]) {cout << "No\n", exit(0);}
    cout << "Yes\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


