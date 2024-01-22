#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
#define pb push_back
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
 
inline ll mul(ll x, ll y, ll m)
{
	ll z = 1LL * x * y;
	if (z >= m)
	    z %= m;
	return z;
}
 
ll n, blockSize, a[100050], b[1000050], m[1000050], up[100050][17], dep[100050], in[100050], c,
	out[100050], ans[100050], rev[200050], val[200050], cur[200050], inv[2000050], moLeft, moRight;
vector<ll> adj[100050];
vector<pair<ll, ll>> f[1000050];

vector<pair<ll, ll>> factors(ll x)
{
	vector<pair<ll, ll>> fac;
	while (x != 1)
	{
	    ll y = b[x], ct = 0;
	    while (x % y == 0)
	        x /= y, ct++;
	    fac.pb({y, ct});
	}
	return fac;
}
void sieve()
{
	f(1, 1000050) b[i] = i;
	f(2, 1000050) b[i] = 2, i++;
	for (ll i = 3; i * i < 1000050; i += 2)
	{
	    if (b[i] == i)
	    {
	        for (ll j = i * i; j < 1000050; j += i)
	            if (b[j] == j)
	                b[j] = i;
	    }
	}
	f(2, 1000050) f[i] = factors(i);
}
 
ll powmod(ll x, ll y)
{
	ll r = 1;
	while (y)
	{
	    if (y & 1)
	        r = mul(r, x, mod);
	    y >>= 1;
	    x = mul(x, x, mod);
	}
	return r;
}
 
ll hilbertorder(ll x, ll y)
{
	ll maxn = 1LL << 20, logn = 20;
	long long d = 0;
	for (ll s = 1 << (logn - 1); s; s >>= 1)
	{
	    bool rx = x & s, ry = y & s;
	    d = d << 2 | rx * 3 ^ static_cast<ll>(ry);
	    if (!ry)
	    {
	        if (rx)
	        {
	            x = maxn - x;
	            y = maxn - y;
	        }
	        swap(x, y);
	    }
	}
	return d;
}

ll tree[2000050];
int timer = 0;
void dfs(int u, int p) {
	in[u] = ++timer;
	tree[timer] = u;
	for (int v : adj[u]) {
		if (v ^ p) {
			up[0][v] = u;
			dep[v] = dep[u] + 1;
			for (int i = 1; i < 17; ++i)
				up[i][v] = up[i - 1][up[i - 1][v]];
			dfs(v, u);
		}
	}
	out[u] = ++timer;
	tree[timer] = u;
}
 
ll lca(ll u, ll v) {
	if (dep[u] != dep[v]) {
		if (dep[u] < dep[v]) swap(u, v);
		int diff = dep[u] - dep[v];
		for (int i = 0; i < K; ++i)
			if (diff & (1 << i))
				u = up[i][u];
	}
	if (u == v) return u;
	for (int i = 0; i < K; ++i) {
		if (up[i][u] != up[i][v]) {
			u = up[i][u];
			v = up[i][v];
		}
	}
	return up[0][u];
}
 

 
void upd(ll v, ll t)
{	
	f(0, f[v].size())
	{
		auto& [j, p] = f[v][i];
	    c = mul(c, inv[m[j] + 1], mod);
		m[j] += t * p;
	    c = mul(c, m[j] + 1, mod);
	    
	}
}
void add(ll in) {
	ll v = tree[in];
	cur[v] ^= 1;
	if (cur[v]) upd(val[v], 1);
	else upd(val[v], -1);
}
void del(ll in) {
	ll v = tree[in];
	cur[v] ^= 1;
	if (cur[v]) upd(val[v], 1);
	else upd(val[v], -1);
}
 
void moQuery(ll l, ll r)
{
	while (moLeft < l)
	    add(moLeft++);
	while (moLeft > l)
	    del(--moLeft);
	while (moRight < r)
	    add(++moRight);
	while (moRight > r)
	    del(moRight--);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	sieve();
	f(0, 2000050) inv[i] = powmod(i, mod - 2);
	ll t, x, y;
	cin >> t;
	while (t--)
	{
	    memset(m, 0, sizeof(m));
	    memset(p, -1, sizeof(p));
	    memset(cur, 0, sizeof(cur));
	    cin >> n;
	    blockSize = sqrt(n);
	    f(0, n + 2) adj[i].clear();
	    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
	    f(1, n + 1) cin >> a[i];
	    c = 1;
	    dfs(1, 0);
	    f(1, n + 1) val[i] = a[i];
		// for (int i = 1; i <= n; ++i) {
		// 	cout << in[i] << " " << out[i] << "\n";
		// }
	    ll q;
	    cin >> q;

		vector <vector <ll>> query;
	    f(1, q + 1)
	    {
	        cin >> x >> y;
			if (in[x] > in[y]) swap(x, y);
	        ll k = lca(x, y);
			ll L, R, p;
	        if (k != x && k != y)
	        {
	           L = out[x];
			   R = in[y];
			   p = in[k];
	        }
	        else
	        {
	            L = in[x];
				R = in[y];
				p = -1;
	        }
			query.push_back({L, R, i, hilbertorder(L, R), p});
	    }
	    sort(query.begin(), query.end(), [&] (vector <ll> q1, vector <ll> q2) {
			return q1[3] < q2[3];
		});
	    c = 1;
	    moLeft = 1, moRight = 0;
	    f(0, query.size())
	    {	
			// for (int i : query[i])
			// 	cout << i << " ";
			// cout << "\n";
	        ll l = query[i][0],
	            r = query[i][1],
	            lca = query[i][4],
	            in = query[i][2];
	        moQuery(l, r);
	        ll currentAns = c;
	        if (lca != -1)
	            add(lca), currentAns = c, del(lca);
	        ans[in] = currentAns;
	    }
	    f(1, q + 1) cout << ans[i] << "\n";
	}
 
	return 0;
}