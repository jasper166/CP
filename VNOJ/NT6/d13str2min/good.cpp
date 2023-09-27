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
#pragma GCC optimize("Ofast")

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

string s;
ll n;
string res;
const int maxN = 2e5 + 5;

struct Segmentree
{
    ii T[4 * maxN];
    Segmentree()
    {
        for (int i = 0; i <= 4 * n; i++)
        {
            T[i] = {1e9 + 5, 0};
        }
    }
    void update(int node, int l, int r, int u, ii val)
    {
        if (l > u || r < u)
        {
            return;
        }
        if (l == r)
        {
            T[node] = {val.fi, -val.se};
            return;
        }
        update(node * 2, l, (l + r) / 2, u, val);
        update(node * 2 + 1, (l + r) / 2 + 1, r, u, val);
        T[node] = min(T[node * 2], T[node * 2 + 1]);
    }
    ii query(int node, int l, int r, int u, int v)
    {
        if (l > v || r < u)
        {
            return {1e9 + 5, 0};
        }
        if (l >= u && r <= v)
        {
            return T[node];
        }
        return min(query(node * 2, l, (l + r) / 2, u, v), query(node * 2 + 1, (l + r) / 2 + 1, r, u, v));
    }
} T1;
string str2min(const string &s, int l, int r)
{
    if (l == r)
    {
        return "";
    }
    string min_ans = "";
    for (int i = l; i < r; ++i)
    {
        string a = str2min(s, l, i);
        string b = str2min(s, i + 1, r);
        string ans;
        ans += s[i];
        ans += a;
        ans += b;
        if (ans < min_ans || min_ans == "")
        {
            min_ans = ans;
        }
    }
    return min_ans;
}

void solve(int l, int r)
{
    if (l == r)
    {
        return;
    }
    ii aa = T1.query(1, 1, n, l, r - 1);
    res.pb(char(aa.fi + 'a'));
    ll bb = -aa.se;
    solve(l, bb);
    solve(bb + 1, r);
}
void progress()
{
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; i++)
    {
        T1.update(1, 1, n, i, {s[i - 1] - 'a', i});
    }
    solve(1, n + 1);
    cout << res;
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

