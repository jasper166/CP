#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#else
#define debug(...) 166
#define debugArr(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int n;
vector <int> adj[MAX];
int in[MAX], out[MAX];

void dfs1(int u, int p) {
    in[u] = 0;
    for (int v : adj[u]) {
        if (v ^ p) {
            dfs1(v, u);
            in[u] = max(in[u], in[v] + 1);
        }
    }
}

void dfs2(int u, int p) {
    int opt1 = -1;
    int opt2 = -1;
    for (int v : adj[u]) {
        if (v ^ p) {
            if (in[v] >= opt1) {
                opt2 = opt1;
                opt1 = in[v];
            }
            else if (in[v] > opt2)
                opt2 = in[v];
        }
    }

    for (int v : adj[u]) {
        if (v ^ p) {
            int in_sib = (in[v] != opt1)? opt1 : opt2;
            out[v] = max(1 + out[u], 2 + in_sib);
            dfs2(v, u);
        }
    }
}
void run_case() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << max(in[i], out[i]) << " \n"[i == n];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

