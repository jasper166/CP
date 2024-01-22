

    #include <bits/stdc++.h>
    //ako ovaj vaso daso misli da me pobedjuje.....
    using namespace std;
    #define int long long
    #define f first
    #define s second
    const int N = 2e5 + 69;
    const int K = 18;
    int up[N][K], a[N], tin[N], tout[N], timer, m;
    int n, q;
    vector<int> g[N];
    set<int> st1[N], st2[N];
    bool anc(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int Lca(int a, int b) {
        if (anc(a, b))
            return a;
        else if (anc(b, a))
            return b;
        for (int i = K - 1;i >= 0;i--) {
            if (!anc(up[a][i], b) && up[a][i] > 0)
                a = up[a][i];
        }
        return up[a][0];
    }
    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1;i < K;i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (auto u : g[v]) {
            if (u == p)
                continue;
            dfs(u, v);
        }
        tout[v] = timer;
    }
     
    signed main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);
      int tt = 1;
      //cin >> tt;
      while (tt--) {
        cin >> n >> m >> q;
        for (int i = 1;i <= n - 1;i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1, 0);
        for (int i = 1;i <= m;i++) {
            cin >> a[i];
            st1[a[i]].insert(i);
        }
        for (int i = 2;i <= m;i++) {
            int x = Lca(a[i], a[i - 1]);
            st2[x].insert(i);
        }
        while (q--) {
            int t;
            cin >> t;
            if (t == 1) {
                int i, v;
                cin >> i >> v;
                int lc;
                if (i > 1) {
                    lc = Lca(a[i], a[i - 1]);
                    st2[lc].erase(i);
                }
                if (i < m) {
                    lc = Lca(a[i], a[i + 1]);
                    st2[lc].erase(i + 1);
                }
                st1[a[i]].erase(i);
                a[i] = v;
                st1[a[i]].insert(i);
                if (i > 1) {
                    lc = Lca(a[i], a[i - 1]);
                    st2[lc].insert(i);
                }
                if (i < m) {
                    lc = Lca(a[i], a[i + 1]);
                    st2[lc].insert(i + 1);
                }
            }
            else {
                int l, r, v;
                cin >> l >> r >> v;
                int x = -1, y = -1;
                auto u1 = st1[v].lower_bound(l);
                auto u2 = st2[v].lower_bound(l + 1);
                if (u1 != st1[v].end() && *u1 <= r) 
                    x = y = *u1;
                else if (u2 != st2[v].end() && *u2 <= r) {
                    y = *u2;
                    x = y - 1;
                }
                cout << x << ' ' << y << '\n';
            }
        }
        }
      return 0;
    }
