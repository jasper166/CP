#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5;

int h[N];
vector <int> ed[N];
vector <pair <int, int>> save;
ll sz[N], cnt = 0, ans = 0, mod = 1e9 + 7;

void dfs(int u, int v) {
    sz[u] = 1;
    cnt++;
    for (auto x : ed[u]) {
        if (x == v)
            continue;

        dfs(x, u);
        sz[u] += sz[x];
    }
}

void dfs2(int u, int v) {
    for (auto x : ed[u]) {
        if (x == v)
            continue;

        dfs2(x, u);
        ll ss = sz[x], re = cnt - ss;
        ll tot = ss * (ss - 1) / 2 * re + re * (re - 1) / 2 * ss;
        tot = (tot + tot) % mod;
        ans = (ans + tot) % mod;
    }
}

int n;

ll solve() {
    for (int i = 1; i <= n; i++) sz[i] = 0;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sz[i] == 0) {
            cnt = 0;
            dfs(i, i);
            dfs2(i, i);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        save.emplace_back(a, b);
        if (max(h[a], h[b]) < t) {
            ed[a].emplace_back(b);
            ed[b].emplace_back(a);
        }
    }

    ll a = solve();
    for (auto x : save) {
        if (max(h[x.first], h[x.second]) == t) {
            ed[x.first].emplace_back(x.second);
            ed[x.second].emplace_back(x.first);
        }
    }

    ll b = solve();
    cout << (b - a + mod) % mod << '\n';
}