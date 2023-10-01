#include <bits/stdc++.h>
using namespace std;

#define task "DDD"
#define pb push_back
const int maxN = 1e2 + 10;
typedef int ll;
ll m, n;
ll x, y;
ll r[maxN], cc[maxN];
ll f[maxN][maxN];
ll c[maxN][maxN];
ll trace[maxN];
char pp[maxN / 2][maxN / 2];
vector<ll> ct[maxN + 5];
bool BFS()
{
    memset(trace, -1, sizeof trace);
    queue<ll> qu;
    qu.push(x);
    trace[x] = 0;
    while (!qu.empty())
    {
        ll u = qu.front();
        qu.pop();
        for (int j = 0; j < ct[u].size(); j++)
        {
            ll v = ct[u][j];
            if (trace[v] == -1 && f[u][v] < c[u][v])
            {
                trace[v] = u;
                qu.push(v);
                if (v == y)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
ll trade()
{
    ll val = 1e9 + 5;
    for (ll v = y; v != x; v = trace[v])
    {
        ll u = trace[v];
        val = min(val, c[u][v] - f[u][v]);
    }
    for (ll v = y; v != x; v = trace[v])
    {
        ll u = trace[v];
        f[u][v] += val;
        f[v][u] -= val;
    }
    return val;
}
void progress()
{
    x = m + n + 1;
    y = m + n + 2;
    ll ss = 0;
    for (int i = 1; i <= m + n + 2; i++)
    {
        ct[i].clear();
    }
    for (int i = 1; i <= m + n + 2; i++)
    {
        for (int j = 1; j <= m + n + 2; j++)
        {
            c[i][j] = 0;
            f[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> r[i];
        ct[x].pb(i);
        c[x][i] = r[i];
        ct[i].pb(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cc[i];
        ss += cc[i];
        ct[i + m].pb(y);
        ct[y].pb(i + m);
        c[i + m][y] = cc[i];
    }
    for (int i = 1; i <= m; i++)
    {
        if (r[i] > n)
        {
            cout << -1;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cc[i] > m)
        {
            cout << -1;
            return;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ct[i].pb(j + m);
            ct[j + m].pb(i);
            c[i][j + m] = 1;
            c[j + m][i] = 0;
        }
    }
    ll res = 0;
    while (BFS())
    {
        res += trade();
    }
    for (int i = 1; i <= m; i++)
    {
        if (f[x][i] != r[i])
        {
            cout << -1;
            return;
        }
    }
    if (res != ss)
    {
        cout << -1;
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (f[i][j + m] == 1)
            {
                pp[i][j] = '1';
            }
            else
                pp[i][j] = '0';
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pp[i][j] == '1')
            {
                c[i][j + m] = 0;
                c[j + m][i] = 0;
                f[i][j + m] -= 1;
                f[j + m][i] += 1;
                ll kq = res - 1;
                f[j + m][y] -= 1;
                f[y][j + m] += 1;
                f[x][i] -= 1;
                f[i][x] += 1;

                while (BFS())
                {
                    kq += trade();
                }

                bool ok = true;
                if (kq != res)
                {
                    ok = false;
                }
                for (int h = 1; h <= m; h++)
                {
                    if (f[x][h] != r[h])
                    {
                        ok = false;
                    }
                }
                if (ok == true)
                {
                    // pp[i][j]='0';
                    for (int h = 1; h <= m; h++)
                    {
                        for (int lp = 1; lp <= n; lp++)
                        {
                            if (f[h][lp + m] != 0)
                            {
                                pp[h][lp] = '1';
                            }
                            else
                                pp[h][lp] = '0';
                        }
                    }
                }
                else
                {
                    c[i][j + m] = 1;
                    c[j + m][i] = 0;
                    f[i][j + m] += 1;
                    f[j + m][i] -= 1;
                    f[j + m][y] += 1;
                    f[y][j + m] -= 1;
                    f[x][i] += 1;
                    f[i][x] -= 1;
                }
            }
            else
            {
                c[i][j + m] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << pp[i][j];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll t;
    t = 1;
    // cin>>t;
    while (cin >> m >> n)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        progress();
        cout << '\n';
    }
}

