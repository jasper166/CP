#include <bits/stdc++.h>
#define task "a"
using namespace std;
typedef long long ll;

const int maxN = 1e5, maxM = 3e5, K = 20;

struct Edge
{
    int x, y, w;
    bool operator<(const Edge &o) const
    {
        return w < o.w;
    }
} E[K + maxM];

int f[maxN + 1], rk[maxN + 1];

int F(int x)
{
    return f[x] ? f[x] = F(f[x]) : x;
}

inline void reset(int n)
{
    fill_n(f + 1, n, 0);
    fill_n(rk + 1, n, 0);
}

inline void merge(int rx, int ry)
{
    if (rx == ry) return;
    if (rk[rx] < rk[ry]) swap(rx, ry);
    f[ry] = rx;
    rk[rx] += rk[rx] == rk[ry];
}

void kruskal(int n, int l, int r, int ans[])
{
    int c = 0;
    reset(n);
    for(int i = l; i < r; i++)
    {
        int x = F(E[i].x), y = F(E[i].y);
        if (x != y)
        {
            merge(x, y);
            ans[c++] = i;
            if (c == n - 1)
            {
                break;
            }
        }
    }
}

int n, m, k, cnt, id[maxN + 1], p[maxN + 1], adj[K + 2], dep[K + 2], fa[K + 2];
ll sum[K + 2], ss[K + 2];
bool b[K + 2], used[2 * K];

struct List
{
    int to, nxt;
    bool b;
} L[2 * K + 1];

int ptr = 1;
inline void add(int x, int y, bool b)
{
    L[ptr] = (List){y, adj[x], b};
    adj[x] = ptr++;
}

void dfs(int u, int p)
{
    ss[u] = sum[u];
    for (int i = adj[u]; i; i = L[i].nxt)
    {
        int v = L[i].to;
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        b[v] = L[i].b;
        dfs(v, u);
        ss[u] += ss[v];
    }
}

inline void update(int &x, int w, ll &ans)
{
    if (!b[x]) return;
    ans += w * ss[x];
    b[x] = false;
}

ll cal(int s)
{
    ptr = 1;
    fill_n(adj + 1, cnt, 0);
    reset(cnt);

    for(int i = 0; i < k; i++)
    {
        if (s & (1 << i))
        {
            int x = E[i].x, y = E[i].y, rx = F(x), ry = F(y);
            if (rx == ry) return 0;
            add(x, y, true);
            add(y, x, true);
            merge(rx, ry);
        }
    }

    for(int i = k ; i < cnt + k - 1; i++)
    {
        int x = E[i].x, y = E[i].y, rx = F(x), ry = F(y);
        if (rx != ry)
        {
            add(x, y, false);
            add(y, x, false);
            merge(rx, ry);
            used[i] = false;
        }
        else
        {
            used[i] = true;
        }
    }

    dfs(1, 0);

    ll ans = 0;

    for(int i = k ; i < cnt + k - 1; i++) 
    {
        if (used[i])
        {
            int x = E[i].x, y = E[i].y, w = E[i].w;
            if (dep[y] < dep[x])
            {
                swap(x, y);
            }
            while (dep[y] != dep[x])
            {
                update(y, w, ans);
                y = fa[y];
            }
            while (x != y)
            {
                update(x, w, ans);
                update(y, w, ans);
                x = fa[x];
                y = fa[y];
            }
        }
    }

    return ans;
}

void progress()
{
    cin >> n >> m >> k;
    for (int i = k; i < k + m; i++)
    {
        cin >> E[i].x >> E[i].y >> E[i].w;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> E[i].x >> E[i].y;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    sort(E + k, E + k + m);

    static int v[maxN - 1];
    kruskal(n, 0, k + m, v);

    reset(n);
    for(int i = 0; i < n - 1; i++)
    {
        if (v[i] >= k)
        {
            merge(F(E[v[i]].x), F(E[v[i]].y));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int j = F(i);
        if (!id[j])
        {
            id[j] = ++cnt;
        }
        sum[id[i] = id[j]] += p[i];
    }
    for (int i = 0; i < k + m; i++)
    {
        E[i].x = id[E[i].x];
        E[i].y = id[E[i].y];
    }

    kruskal(cnt, k, k + m, v);

    for (int i = 0; i < cnt - 1; i++)
    {
        E[k + i] = E[v[i]];
    }

    ll ans(0);
    for (int s = (1 << k) - 1; s >= (1 << (k - min(k, 2))); s--)
    {
        ans = max(ans, cal(s));
    }
    cout << ans;
}

// main
int main()
{
    // Written by Shyn_
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll nt = 1;
    // cin >> nt;
    for (; nt--;)
    {
        progress();
    }
}
/** LeSonnn_ **/
/** LCG **/

