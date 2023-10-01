/**
 *Author: Le Son - TK2._CHT
 *Spawn: 01/10/2006 - Ha Tinh City - VN
 *School: Ha Tinh High School for the Gifted
**/
#include <bits/stdc++.h>
#define task "testa"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ll> ip;
//#pragma GCC optimize("Ofast")

// struct-----pair
#define mp make_pair
#define fi first
#define se second
#define all(a_) a_.begin(), a_.end()
#define mask(x) (1LL << (x))

// vector
#define pb push_back
#define eb emplace_back
#define sz(a) (int)(a.size())

// max - min
template <class shark>
inline bool minimize(shark &a, const shark &b) { return (a > b ? (a = b), 1 : 0); }
template <class shark>
inline bool maximize(shark &a, const shark &b) { return (a < b ? (a = b), 1 : 0); }

// declare

const int maxN = 1e5 + 11;
ll n, m, k;
ll u[maxN], v[maxN];
ll ta[maxN];
vector<ll> vt[maxN];
map<ip, ll> M;
ll ss[5];
ll res;
vector<ii> superpower[maxN];
map<ii, ll> mpa, mpb;
bool DD[maxN];
ll par[maxN][20], dp[maxN][20], sz[maxN];

void DFS(int u)
{
    DD[u] = 1;
    for (auto v : superpower[u])
    {
        if (DD[v.fi] == 1)
        {
            continue;
        }
        sz[v.fi] = sz[u] + 1;
        par[v.fi][0] = u;
        dp[v.fi][0] = v.se;
        for (int i = 1; i <= 17; i++)
        {
            par[v.fi][i] = par[par[v.fi][i - 1]][i - 1];
            dp[v.fi][i] = dp[par[v.fi][i - 1]][i - 1] + dp[v.fi][i - 1];
        }
        DFS(v.fi);
    }
}
ll LCA(int u, int v)
{
    if (sz[u] > sz[v])
    {
        swap(u, v);
    }
    ll res = 0;
    for (int i = 17; i >= 0; i--)
    {
        if (sz[v] - mask(i) >= sz[u])
        {
            res += dp[v][i];
            v = par[v][i];
        }
    }
    if (u == v)
    {
        return res;
    }
    for (int i = 17; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            res += dp[u][i];
            res += dp[v][i];
            u = par[u][i];
            v = par[v][i];
        }
    }
    if (u != v)
    {
        res += dp[u][0];
        res += dp[v][0];
        u = par[u][0];
        v = par[v][0];
    }
    return res;
}
void progress()
{
    cin >> n >> k;
    for (int i = 1; i <= n - 3; i++)
    {
        cin >> u[i] >> v[i] >> ta[i];
        mpb[{u[i], v[i]}] = mpb[{v[i], u[i]}] = ta[i];
        vt[u[i]].push_back(v[i]);
        vt[v[i]].push_back(u[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            vt[1].push_back(2);
            vt[1].push_back(n);
        }
        else if (i == n)
        {
            vt[n].push_back(1);
            vt[n].push_back(n - 1);
        }
        else
        {
            vt[i].push_back(i - 1);
            vt[i].push_back(i + 1);
        }
        sort(vt[i].begin(), vt[i].end());
        vector<ll> rt;
        vector<ll> ct;
        for (auto vv : vt[i])
        {
            if (vv > i)
            {
                rt.push_back(vv);
            }
            else
                ct.push_back(vv);
        }
        vt[i].clear();
        for (auto vv : rt)
        {
            vt[i].push_back(vv);
        }
        for (auto vv : ct)
        {
            vt[i].push_back(vv);
        }
        ll pp = 0;
        if (vt[i].size() > 2)
        {
            for (int j = 1; j < vt[i].size(); j++)
            {
                ll aa = vt[i][j - 1];
                ll bb = vt[i][j];
                ss[1] = i;
                ss[2] = aa;
                ss[3] = bb;
                sort(ss + 1, ss + 4);
                if (M[{{ss[1], ss[2]}, ss[3]}] == 0)
                {
                    res++;
                    if (ss[1] + 1 == ss[2])
                    {
                        mpa[{ss[1], ss[2]}] = mpa[{ss[2], ss[1]}] = res;
                    }
                    if (ss[2] + 1 == ss[3])
                    {
                        mpa[{ss[3], ss[2]}] = mpa[{ss[2], ss[3]}] = res;
                    }
                    if (ss[1] == 1 && ss[3] == n)
                    {
                        mpa[{ss[1], ss[3]}] = mpa[{ss[3], ss[1]}] = res;
                    }
                    M[{{ss[1], ss[2]}, ss[3]}] = res;
                }
                if (j != 1)
                {
                    ll mmm = M[{{ss[1], ss[2]}, ss[3]}];
                    superpower[mmm].push_back({pp, mpb[{i, aa}]});
                    superpower[pp].push_back({mmm, mpb[{i, aa}]});
                }
                pp = M[{{ss[1], ss[2]}, ss[3]}];
            }
        }
    }
    DFS(1);
    for ( ; k--;)
    {
        ll aa, bb;
        cin >> aa >> bb;
        ll fir = mpa[{aa, aa % n + 1}];
        ll sec = mpa[{bb, bb % n + 1}];
        cout << LCA(fir, sec) << '\n';
    }
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

