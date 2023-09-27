#include <bits/stdc++.h>
#define task "a"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
const int maxn = 1e6 + 5;
int n, m, k;

int u[maxn], v[maxn], w[maxn], par[maxn], num[maxn], add[maxn], val[maxn];

int uf(int x, int y, int w)
{
    int mx = 0;
    while (x != y && (x != par[x] || y != par[y]))
    {
        if (x == par[x] || (par[y] != y && num[y] <= num[x]))
        {
            mx = max(mx, val[y]);
            y = par[y];
        }
        else
        {
            mx = max(mx, val[x]);
            x = par[x];
        }
    }
    if (x != y)
    {
        if (num[x] > num[y])
            swap(x, y);
        par[x] = y;
        val[x] = w;
        num[y] += num[x];
        return 1;
    }
    return -mx;
}

void progress()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        num[i] = 1;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        pq.push({w[i], i});
    }
    ll mst = 0;
    while (!pq.empty())
    {
        ii tmp = pq.top();
        pq.pop();
        int vv = uf(u[tmp.se], v[tmp.se], tmp.fi);
        if (vv == 1)
        {
            mst += tmp.fi;
            add[tmp.se] = 0;
        }
        else
        {
            add[tmp.se] = vv + tmp.fi;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << mst + add[i] << '\n';
    }
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

