/**
 *Author: Le Son - TK2._CHT
 *Spawn: 01/10/2006 - Ha Tinh City - VN
 *School: Ha Tinh High School for the Gifted
 **/
#include <bits/stdc++.h>
#define task "fruit"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;

// struct-----pair
#define mp make_pair
#define fi first
#define se second
#define all(a_) a_.begin(), a_.end()

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
const ll maxN = 3e5 + 11;
const ll mod = 1e9 + 7;
const ll base = 31;

ll n, q;
string s, t;
ll tree[maxN * 4], IT[maxN * 4];
ll pw[maxN];
void update(int node, int l, int r, int u, char c)
{
    if (l == r)
    {
        tree[node] = c - 'a' + 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (u <= mid)
        update(node * 2, l, mid, u, c);
    else
        update(node * 2 + 1, mid + 1, r, u, c);
    tree[node] = (tree[node * 2] * pw[r - mid] + tree[node * 2 + 1] % mod) % mod;
}
pair<ll, int> get(int node, int l, int r, int u, int v)
{
    if (u > r || v < l)
        return {0LL, 0};
    if (u <= l && r <= v)
        return {tree[node], r - l + 1};
    int mid = (l + r) >> 1;
    auto fir = get(node * 2, l, mid, u, v);
    auto sec = get(node * 2 + 1, mid + 1, r, u, v);
    return {(fir.fi * pw[sec.se] + sec.fi % mod) % mod, fir.se + sec.se};
}
void else_update(int node, int l, int r, int u, char c)
{
    if (l == r)
    {
        IT[node] = c - 'a' + 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (u <= mid)
        else_update(node * 2, l, mid, u, c);
    else
        else_update(node * 2 + 1, mid + 1, r, u, c);
    IT[node] = (IT[node * 2] + IT[node * 2 + 1] * pw[mid - l + 1] % mod) % mod;
}
pair<ll, int> else_get(int node, int l, int r, int u, int v)
{
    if (u > r || v < l)
        return {0LL, 0};
    if (u <= l && r <= v)
        return {IT[node], r - l + 1};
    int mid = (l + r) >> 1;
    auto fir = else_get(node * 2, l, mid, u, v);
    auto sec = else_get(node * 2 + 1, mid + 1, r, u, v);
    return {(fir.fi + sec.fi * pw[fir.se] % mod) % mod, fir.se + sec.se};
}
void progress()
{
    cin >> n >> q >> s;
    s = " " + s;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pw[i] = (pw[i - 1] * base) % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        update(1, 1, n, i, s[i]);
        else_update(1, 1, n, i, s[i]);
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int id;
            char c;
            cin >> id >> c;
            update(1, 1, n, id, c);
            else_update(1, 1, n, id, c);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            if (get(1, 1, n, l, r).fi == else_get(1, 1, n, l, r).fi)
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }
}
// main
int main()
{
    // Written by Shyn_
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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

