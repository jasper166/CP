#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n;
vector <int> adj[MAX];
int sz[MAX], dep[MAX];
bool vis[MAX];
int Tsize;

void reSubsize(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !vis[v]) {
            reSubsize(v, u);
            sz[u] += sz[v];
        }
    }
}

int getCentroid(int u, int p) {
    for (int v : adj[u]) {
        if (v != p && !vis[v] && sz[v] > Tsize / 2)
            return getCentroid(v, u);
    }
    return u;
}


void decompose(int u, int p) {
    reSubsize(u, 0);
    Tsize = sz[u];
    int x = getCentroid(u, 0);

    vis[x] = 1;
    dep[x] = dep[p] + 1;
    for (int v : adj[x]) {
        if (!vis[v])
            decompose(v, x);
    }

}


void run_case() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    decompose(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << (char) (dep[i] - 1 + 'A') << " \n"[i == n];
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in2", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
