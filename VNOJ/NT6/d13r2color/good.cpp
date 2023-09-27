#include <bits/stdc++.h>
#define task "a"
using namespace std;
typedef long long ll;
const int maxN = 1e5 + 9;
ll n, m, k;
ll a[3 * maxN], DD[3 * maxN];
bool b[3 * maxN];
vector<int> adj[maxN], vt;

bool DFS(int u, int c)
{
    vt.emplace_back(u);
    DD[u] = c;
    bool flag = true;
    for (int &v : adj[u])
    {
        if (DD[v])
        {
            if (DD[v] == DD[u]) return false;
        }
        else
        {
            flag &= DFS(v, 3 - c);
        }
    }
    return flag;
}

void progress()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!DD[i])
        {
            vt.clear();
            if (!DFS(i, 1))
            {
                ans += n;
                continue;
            }
            int pre_res(0), res(0);
            for (int u : vt)
            {
                if (DD[u] != a[u])
                {
                    if (!b[u])
                    {
                        pre_res = n;
                    }
                    else
                    {
                        pre_res++;
                    }
                }
                DD[u] = 3 - DD[u];
                if (DD[u] != a[u])
                {
                    if (!b[u])
                    {
                        res = n;
                    }
                    else
                    {
                        res++;
                    }
                }
            }

            ans += min(pre_res, res);
        }
    }
    if(ans >= n)
    {
        cout << -1;
        return;
    }
    cout << ans;
}

int main()
{
    // Author: Shyn_
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll nt = 1;
    //cin >> nt;
    for (; nt--;)
    {
        progress();
    }
}

