#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define           f     first
#define           s     second
#define           pb    push_back
#define           ep    emplace
#define           eb    emplace_back
#define           lb    lower_bound
#define           ub    upper_bound
#define       all(x)    x.begin(), x.end()
#define      rall(x)    x.rbegin(), x.rend()
#define   uniquev(v)    sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define     mem(f,x)    memset(f , x , sizeof(f))
#define        sz(x)    (int)(x).size()
#define  __lcm(a, b)    (1ll * ((a) / __gcd((a), (b))) * (b))
#define          mxx    *max_element
#define          mnn    *min_element
#define    cntbit(x)    __builtin_popcountll(x)
#define       len(x)    (int)(x.length())

const int N = 5e5 + 10;
vector <int> adj[N];

int a[N];
ll dp[N][31][2], sz[N];

void dfs(int u, int v) {
    sz[u]++;
    for (auto x : adj[u]) {
        if (x == v)
            continue;

        dfs(x, u);
        sz[u] += sz[x];
        for (int i = 0; i < 20; i++) {
            int t = bool(a[u] & (1 << i));
            dp[u][i][t] += dp[x][i][t];
            dp[u][i][1 - t] += dp[x][i][t];
        }
    }

    for (int i = 0; i < 20; i++) {
        int t = bool(a[u] & (1 << i));
        dp[u][i][1 - t] += sz[u];
    }
}

// u is v's parent
void reroot(int u, int x) {
    for (int i = 0; i < 20; i++) {
        int t = bool(a[u] & (1 << i));
        dp[u][i][t] -= dp[x][i][t];
        dp[u][i][1 - t] -= dp[x][i][t];
    }

    ll pr = sz[u];
    sz[u] -= sz[x];
    for (int i = 0; i < 20; i++) {
        int t = bool(a[u] & (1 << i));
        dp[u][i][1 - t] -= pr;
        dp[u][i][1 - t] += sz[u];
    }

    for (int i = 0; i < 20; i++) {
        int t = bool(a[x] & (1 << i));
        dp[x][i][1 - t] += sz[u];
    }

    sz[x] += sz[u];

    for (int i = 0; i < 20; i++) {
        int t = bool(a[x] & (1 << i));
        dp[x][i][t] += dp[u][i][t];
        dp[x][i][1 - t] += dp[u][i][t];
    }
}

ll ans[N];
void dfs2(int u, int v) {
    ll sum = 0;
    for (int i = 0; i < 20; i++) {
        ll v = (1 << i);
        sum += min(dp[u][i][0], dp[u][i][1]) * v;
    }

    ans[u] = sum;
    for (auto x : adj[u]) {
        if (x == v)
            continue;

        reroot(u, x);
        dfs2(x, u);
        reroot(x, u);
    }
}

ll solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 1);
    dfs2(1, 1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
        adj[i].clear();
        mem(dp[i], 0);
        sz[i] = 0;
    }

    cout << '\n';
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        //cout << solve() << '\n';
    }
}
