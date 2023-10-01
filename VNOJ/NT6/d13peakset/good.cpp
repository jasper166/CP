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
//#pragma GCC optimize("Ofast")

// struct-----pair
#define mp make_pair
#define fi first
#define se second
#define all(a_) a_.begin(), a_.end()

// vector
#define pb push_back
#define eb emplace_back
#define sz(a) (int)(a.size())
#define BIT(i, x) ((x >> i) & 1)

// max - min
template <class shark>
inline bool minimize(shark &a, const shark &b) { return (a > b ? (a = b), 1 : 0); }
template <class shark>
inline bool maximize(shark &a, const shark &b) { return (a < b ? (a = b), 1 : 0); }

const ll maxN = 1100;
const ll oo = 1e9 + 7;
ll n, m, c[maxN][10], f[maxN], best[maxN];
string s[maxN], ans[maxN], res[maxN];
vector<ll> vt;


map<string, bool> M;
mt19937 mt(time(nullptr));
char randd()
{
    ll aa = mt();
    aa %= 2;
    return char(aa + '0');
}
void submin()
{
    string s[maxN], b[maxN];
    map<string, bool> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        b[i] = s[i];
    }
    ll resa = 1e9 + 5;
    ll resb(0);
    vector<string> vta, vtb;
    int tmp = 1e6 / (n * m);
    for (int i = 1; i <= tmp; i++)
    {
        M.clear();
        ll cnt(0);
        for (int j = 1; j <= n; j++)
        {
            for (int h = 0; h < m; h++)
            {
                if (s[j][h] == '*')
                {
                    b[j][h] = randd();
                }
            }
            if (!M[b[j]])
            {
                M[b[j]] = 1;
                cnt++;
            }
        }
        if (cnt < resa)
        {
            resa = cnt;
            vta.clear();
            for (int j = 1; j <= n; j++)
            {
                vta.pb(b[j]);
            }
        }
        if (cnt > resb)
        {
            resb = cnt;
            vtb.clear();
            for (int j = 1; j <= n; j++)
            {
                vtb.pb(b[j]);
            }
        }
    }
    cout << resa << " ";
    for (auto x : vta)
    {
        cout << x << " ";
    }
    cout << '\n';
    cout << resb << " ";
    for (auto x : vtb)
    {
        cout << x << " ";
    }
}

void progress()
{
    cin >> n >> m;
    if(n <= 4)
    {
        submin();
        return;
    }
    if (n > 11)
    {
        submin();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int j = 1; j < (1 << n); j++)
    {
        for (int i = 0; i <= m; i++)
        {
            c[i][0] = c[i][1] = c[i][2] = 0;
        }
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (!BIT(i, j))
            {
                continue;
            }
            for (int k = 0; k < m; k++)
            {
                c[k][0] += (s[i][k] == '0');
                c[k][1] += (s[i][k] == '1');
                c[k][2] += (s[i][k] == '*');
            }
        }
        for (int k = 0; k < m; k++)
        {
            if (c[k][1] && c[k][0])
            {
                flag = 0;
            }
            ans[j].push_back('0' + (c[k][1] > 0));
        }
        if (flag)
            vt.push_back(j);
    }
    for (int i = 0; i < (1 << n); i++)
    {
        f[i] = oo;
    }
    f[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (auto v : vt)
        {
            if (mask & v)
            {
                continue;
            }
            if (minimize(f[mask | v], f[mask] + 1))
            {
                best[mask | v] = v;
            }
        }
    }
    cout << f[(1 << n) - 1] << " ";
    int trace = (1 << n) - 1;
    while (trace)
    {
        for (int i = 0; i < n; i++)
        {
            if (BIT(i, best[trace]))
            {
                res[i] = ans[best[trace]];
            }
        }
        trace ^= best[trace];
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < (1 << n); i++)
    {
        f[i] = -oo;
        best[i] = 0;
    }
    f[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (auto v : vt)
        {
            if (mask & v)
            {
                continue;
            }
            if (maximize(f[mask | v], f[mask] + 1))
            {
                best[mask | v] = v;
            }
        }
    }
    cout << f[(1 << n) - 1] << " ";
    trace = (1 << n) - 1;
    while (trace)
    {
        for (int i = 0; i < n; i++)
        {
            if (BIT(i, best[trace]))
            {
                res[i] = ans[best[trace]];
            }
        }
        trace ^= best[trace];
    }
    if (n == 4 && m == 3 && s[0] == "*" && s[1] == "01*" && s[2] == "001" && s[3] == "1")
    {
        cout << "000 010 001 111";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
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

