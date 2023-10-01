#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define Unique(x) (x).resize(distance((x).begin(), unique(all((x)))))
#define getbit(x, i) ((x >> i) & 1)
#define biton(x, i) (x | (1 << (i - 1)))
#define bitoff(x, i) (x & ~(1 << (i - 1)))
#define cntbit(x) (__builtin_popcount(x))

const ll mod = 1e9 + 7;
const ll base = 31;
const ll nmax = 300005;

int n, q;
pair<ll, ll> a[nmax];
pair<ll, int> b[nmax];
int l[nmax], r[nmax], L[nmax], R[nmax];
vector<pair<int, int> > query[nmax];
vector<pair<int, ll> > pos[nmax];
ll ans[nmax];
ll tree[nmax * 4];
void processLR()
{
    for(int i = 1; i <= n; i++)
    {
        l[i] = i - 1;
        while(l[i] > 0 && a[b[l[i]].se].se >= a[b[i].se].se)
            l[i] = l[l[i]];
    }
    for(int i = n; i >= 1; i--)
    {
        r[i] = i + 1;
        while(r[i] <= n && a[b[r[i]].se].se >= a[b[i].se].se)
             r[i] = r[r[i]];
    }
}
void build(int node, int l, int r)
{
    if(l == r)
    {
        tree[node] = 1e18;
        return;
    }
    int mid = (l + r) >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
void update(int node, int l, int r, int idx, ll val)
{
    if(idx < l || idx > r)
        return;
    if(l == r)
    {
        tree[node] = min(tree[node], val);
        return;
    }
    int mid = (l + r) >> 1;
    update(node * 2, l, mid, idx, val);
    update(node * 2 + 1, mid + 1, r, idx, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
ll get(int node, int l, int r, int u, int v)
{
    if(v < l || u > r)
        return 1e18;
    if(l >= u && r <= v)
        return tree[node];
    int mid = (l + r) >> 1;
    return min(get(node * 2, l, mid, u, v), get(node * 2 + 1, mid + 1, r, u, v));
}
void solve()
{
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i].fi>>a[i].se;
        b[i].fi = a[i].fi;
        b[i].se = i;
    }
    sort(b + 1, b + 1 + n);
    processLR();
    for(int i = 1; i <= n; i++)
    {
        if(l[i] > 0)
            L[b[i].se] = b[l[i]].se;
        else
            L[b[i].se] = -1;
        if(r[i] <= n)
            R[b[i].se] = b[r[i]].se;
        else
            R[b[i].se] = -1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(L[i] != -1)
        {
            if(L[i] > i)
                pos[L[i]].push_back({i, (a[i].se + a[L[i]].se) * abs(a[i].fi - a[L[i]].fi)});
            else
                pos[i].push_back({L[i], (a[i].se + a[L[i]].se) * abs(a[i].fi - a[L[i]].fi)});
        }
        if(R[i] != -1)
        {
            if(R[i] > i)
                pos[R[i]].push_back({i, (a[i].se + a[R[i]].se) * abs(a[i].fi - a[R[i]].fi)});
            else
                pos[i].push_back({R[i], (a[i].se + a[R[i]].se) * abs(a[i].fi - a[R[i]].fi)});
        }
    }
    for(int i = 1; i <= q; i++)
    {
        int x, y;
        cin>>x>>y;
        query[y].push_back({x, i});
    }
    build(1, 1, n);
    for(int i = 1; i <= n; i++)
    {
        for(auto j : pos[i])
            update(1, 1, n, j.fi, j.se);
        for(auto j : query[i])
            ans[j.se] = get(1, 1, n, j.fi, i);
    }
    for(int i = 1; i <= q; i++)
        cout<<ans[i]<<'\n';
}
int main()
{
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--)
    {
         solve();
         //cout<<'\n';
    }
}
