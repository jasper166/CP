#include "bits/stdc++.h"
#include <numeric>
// @Jasper
using namespace std;
using ll = long long;

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e2 + 5;

int a[MAX][MAX];
using T = tuple <int, int, int>;
vector <pair<int, int>> adj[MAX];
int d[MAX];

void run_case(){
    int n; cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cin >> a[i][j];
    //         if (a[i][j]) 
    //             adj[i].push_back({a[i][j], j});
    //     }
    //     d[i] = INF;
    // }
    
    int m; cin >> m;
    for (int i = 1; i <= n; i++) d[i] = INF;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int s; cin >> s;
    d[s] = 0;
    priority_queue <T, vector <T>, greater <T>> q;
    q.push({0, s, 0});

    int res = 0;
    vector <T> mst;
    while (!q.empty()) {
        auto [du, u, pre] = q.top(); q.pop();
        if (du != d[u])
            continue;

        res += d[u];
        if (pre) {
            int P = pre;
            int U = u;
            mst.push_back({a[P][U], P, U});
        }
        d[u] = -INF;
        for (auto [w, v] : adj[u]) {
            if (w < d[v]) {
                d[v] = w;
                q.push({d[v], v, u});
            }
        }
    }
    
    if (mst.size() != n - 1) {
        cout << "Do thi khong lien thong\n";
        return;
    }
    sort(mst.begin(), mst.end());
    for (auto [w, u, v] : mst) {
        if (u > v) swap(u, v);
        cout << u << " " << v << "\n";
    }
    cout << res << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    while (Test--){

        run_case();
    }
}
