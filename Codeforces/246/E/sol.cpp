#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;


int n, q;
vector <int> adj[MAX];
int sz[MAX], dep[MAX];
int c[MAX];

void cal(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v ^ p) {
            dep[v] = dep[u] + 1;
            cal(v, u);
            sz[u] += sz[v];
        }
    }
}

vector <int> sub[MAX];
vector <pii> que[MAX];
set <int> cnt[MAX]; 
int ans[MAX];

void dfs(int u, int p, bool isHeavy) {
    int hvy = -1;
    int mx = 0;
    for (int v : adj[u]) 
        if (v ^ p) 
            if (mx < sz[v]) {
                hvy = v;
                mx = sz[v];
            }

    for (int v : adj[u])
        if (v ^ p && v != hvy)
            dfs(v, u, 0);
    if (hvy != -1) {
        dfs(hvy, u, 1);
        swap(sub[u], sub[hvy]);
    }
    sub[u].push_back(u);
    cnt[dep[u]].insert(c[u]);
    for (int v : adj[u]) {
        if (v ^ p && v != hvy) {
            for (int x : sub[v]) {
                sub[u].push_back(x);
                cnt[dep[x]].insert(c[x]);
            }
        }
    }

    for (auto [k, id] : que[u])
        if (dep[u] + k <= n)
            ans[id] = cnt[dep[u] + k].size();

    if (!isHeavy)
        for (int v : sub[u])
            cnt[dep[v]].erase(c[v]);

}



void run_case() {
    cin >> n;
    map <string, int> mp;

    int j = 1;
    for (int i = 1; i <= n; ++i) {
        string name;
        int x;
        cin >> name >> x;
        if (!mp.count(name))
            mp[name] = j++;
        c[i] = mp[name];
        adj[x].push_back(i);
        adj[i].push_back(x);
        
    }
    cal(0, -1);
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int v, k;
        cin >> v >> k;
        que[v].push_back({k, i});
    }
    dfs(0, -1, 1);
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


