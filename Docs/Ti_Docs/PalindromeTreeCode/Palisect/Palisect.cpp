#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1e18
#define MIN -1e18
#define MOD 51123987
//#define mod2 20071027
//#define MOD 998244353
#define base 139
//#define mod 1000074259
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case #%d: ", ++c)
#define out(x) cout << #x << " -> " << x << endl;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE   freopen("input.txt", "r", stdin);  freopen("out.txt", "w", stdout);
using namespace std;
const int N = 2000005;
int avail, sz, tc;
int len[N], link[N], t, cur, node[N],occ[N],  a[N], tocc[N];
// ll  b[N];
string s, r; // 1-indexed
vector<pair<int, int>>tree[N];
void init()
{
    for(int i=0; i<N-3; i++)
    {
        tree[i].clear();
    }
    memz(occ);
    memz(tocc);
    len[1] = -1, link[1] = 1;
    len[2] = 0, link[2] = 1;
    avail = cur = 2;
    s = "$" + s;
}
void extend(int pos)
{
    while (s[pos - len[cur] - 1] != s[pos]) cur = link[cur];
    int x = link[cur], c = s[pos] - 'a';
    while (s[pos - len[x] - 1] != s[pos]) x = link[x];
    int ok = 0;
    for (auto u : tree[cur])
    {
        if (u.second == c)
            ok = u.first;
    }
    if (!ok)
    {
        tree[cur].pb({++avail, c});
        len[avail] = len[cur] + 2;
        if (len[avail] == 1)
            link[avail] =  2 ;
        else
        {
            for(auto u:tree[x])
            {
                if(u.second==c)
                {
                    ok=u.first;
                }
            }
            link[avail]=ok;
        }
        cur = avail;
    }
    else cur = ok;
    tocc[cur]++;
    node[pos] = cur;
}
int dfs(int x)
{
    if (x < 3) return 0;
    if (occ[x]) return occ[x];
    return occ[x] = 1 + dfs(link[x]);
}
void pl_tree()
{
    init();
    for (int i = 1; i <= sz; i++)
    {
        extend(i);
    }
    for (int i = 3; i <= avail; i++)
        if (occ[i] == 0)
        {
            occ[i] = dfs(i);
        }
}

int solve()
{
    freopen("PALISECT.INP","r",stdin);
    cin >> sz >> s;
    r = s;
    ll res = 0;
    pl_tree();
    for (int i = 1; i <= sz; i++)
        a[i] = occ[node[i]];
    reverse(r.begin(), r.end());
    s = r;
    pl_tree();
    ll b=0;
    for (int i = 1; i < sz; i++)
    {
        b = (b + occ[node[i]])%MOD;
        res = (res+(b*a[sz-i])%MOD)%MOD;
    }
    ll tot = 0;
    for (int i = avail; i > 2; i--)
    {
        tocc[link[i]] += tocc[i];
        tot += (ll)tocc[i];
    }
    ll x=tot, y=tot-1;
    if(y%2==0) y/=2;
    else x/=2;
    tot = ((x%MOD)*(y%MOD))%MOD;
    // for (int i = 1; i < sz; i++) {
    // 	res = (res+(a[i] * b[sz - i])%MOD)%MOD;
    // }
    ll fin = (tot-res)%MOD;
    if(fin<0) fin+=MOD;
    cout<<fin;
    //printf("%lld\n", fin);
    return 0;
}
int main()
{
    freopen("PALISECT.INP","r",stdin);
    freopen("PALISECT.OUT","w",stdout);
    return solve();
}
