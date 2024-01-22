#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 2e5 + 5;
int n, m;
vector <int> adj[N << 1];
int deg[N << 1], a[N << 1];

bool check(int k) {
    for (int i = 0; i <= k; ++i) {
        if (i + m <= k) {
            adj[i].push_back(i + m);
            deg[i + m]++;
        }
        if (i >= n) {
            adj[i].push_back(i - n);
            deg[i - n]++;
        }
    }

    queue <int> q;
    for (int i = 0; i <= k; ++i)
        if (deg[i] == 0)
            q.push(i);

    int cnt = 0;
    vector <int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        a[u] = ++cnt;
        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
    for (int i = 0; i <= k; ++i) {
        adj[i].clear();
        deg[i] = 0;
    }
    // if the graph is cyclic then no topo order exists
    return ((int) topo.size() == k + 1);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int T; 
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int ans = (n + m - 1 - __gcd(n, m));
        check(ans);
        cout << ans << "\n";
        for (int i = 1; i <= ans; ++i) {
            cout << (a[i] - a[i - 1]) << " \n"[i == ans];
        }   
    }
}


