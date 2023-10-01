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
const int MAX = 1e5 + 5;

int n, m;
vector <int> edges[MAX];
int vis[MAX];
int p[MAX];

void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) p[i] = -1;
    FOR(i, 1, m){
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    queue <int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()){
        int u = q.front(); q.pop();
        
        for (int v : edges[u]){
            if (!vis[v]){
                vis[v] = 1;
                p[v] = u;
                q.push(v);
            }
        }
    }

    int u = n;
    if (p[u] == -1) cout << "IMPOSSIBLE\n", exit(0);
  
    vector <int> path;
    while (u != -1){
        path.push_back(u);
        u = p[u];
    }
    reverse(all(path));
    cout << path.size() << "\n";
    for (int u : path) cout << u << " ";
    cout << "\n";
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




