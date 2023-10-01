#include <bits/stdc++.h>
#define task "colortab"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;
#define fi first
#define se second
const int maxN = 53;

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};

int n, m, k;
vector<int> adj[maxN][maxN];
int f[maxN][maxN], c[maxN][maxN];

ii cnt[2 * maxN];
set<ii> s[2 * maxN];
ii it;

vector<int> ways;
vector<ii> vt[maxN], color, new_color;
vector<iiii> ans;

queue<ii> q;

void Update(int x, int y)
{
    if (x == 1 && y == 1)
    {
        return;
    }
    ways.clear();
    int u = x, v = y, tmp;
    while (u + v != 2)
    {
        ways.push_back(f[u][v]);
        tmp = f[u][v];
        ans.push_back({{u, v}, {u - dx[tmp], v - dy[tmp]}});
        u -= dx[tmp];
        v -= dy[tmp];
    }
    u += dx[ways.back()], v += dy[ways.back()];
    for (int i = ways.size() - 2; i >= 0; --i)
    {
        tmp = ways[i];
        ans.push_back({{u, v}, {u + dx[tmp], v + dy[tmp]}});
        u += dx[tmp];
        v += dy[tmp];
    }
}

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i].fi + cnt[2 * n - i + 1].fi != m)
        {
            return false;
        }
    }
    return true;
}

void progress()
{
    cin >> m >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        cnt[i] = {0, i};
        s[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            s[c[i][j]].insert({i, j});
            cnt[c[i][j]].fi++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = -2;
        }
    }
    int u, v;
    q.push({1, 1});
    f[1][1] = -1;
    while (q.size())
    {
        tie(u, v) = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            if (u + dx[i] >= 1 && u + dx[i] <= m && v + dy[i] >= 1 && v + dy[i] <= n && f[u + dx[i]][v + dy[i]] == -2)
            {
                f[u + dx[i]][v + dy[i]] = i;
                q.push({u + dx[i], v + dy[i]});
            }
        }
    }
    sort(cnt + 1, cnt + 1 + 2 * n);
    ans.clear();
    for (int i = 1; i <= n; i++)
    {
        vt[i].clear();
    }
    if (check())
    {
        for (int i = 1; i <= n; i++)
        {
            vt[i].push_back(cnt[i]);
            vt[i].push_back(cnt[2 * n - i + 1]);
        }
    }
    else
    {
        color.clear();
        for (int i = 1; i <= 2 * n; i++)
        {
            color.push_back(cnt[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (color.size() == 1)
            {
                vt[i].push_back({m, color.back().se});
                color.back().fi -= m;
            }
            else
            {
                int id(0);
                while (color[id].fi + color[id + 1].fi + color.back().fi < m)
                {
                    id++;
                }
                int pre = m, res;
                res = min(pre, color[id].fi);
                vt[i].push_back({res, color[id].se});
                pre -= res;
                color[id].fi -= res;
                if (pre)
                {
                    res = min(pre, color[id + 1].fi);
                    vt[i].push_back({res, color[id + 1].se});
                    pre -= res;
                    color[id + 1].fi -= res;
                }
                if (pre)
                {
                    res = min(pre, color.back().fi);
                    vt[i].push_back({res, color.back().se});
                    pre -= res;
                    color.back().fi -= res;
                }
            }
            new_color.clear();
            for (auto x : color)
            {
                if (x.fi > 0)
                {
                    new_color.push_back(x);
                }
            }
            sort(new_color.begin(), new_color.end());
            swap(new_color, color);
        }
    }
    for (int j = 1; j <= n; j++)
    {
        int id = 0;
        for (auto x : vt[j])
        {
            for (int i = id + 1; i <= id + x.fi; i++)
            if (c[i][j] == x.se)
            {
                s[c[i][j]].erase({i, j});
            }
            else
            {
                it = *s[x.se].begin();
                s[c[i][j]].erase({i, j});
                s[c[it.fi][it.se]].erase({it.fi, it.se});
                s[c[i][j]].insert({it.fi, it.se});
                s[c[it.fi][it.se]].insert({i, j});
                swap(c[i][j], c[it.fi][it.se]);
                Update(i, j);
                Update(it.fi, it.se);
                Update(i, j);
                s[x.se].erase({i, j});
            }
            id += x.fi;
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans)
    {
        cout << x.fi.fi << " " << x.fi.se << " " << x.se.fi << " " << x.se.se << '\n';
    }
}

signed main()
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
    cin >> nt;
    for (; nt--;)
    {
        progress();
    }
}

