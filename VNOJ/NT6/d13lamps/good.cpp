/**
 *Author: Le Son - TK2._CHT
 *Spawn: 01/10/2006 - Ha Tinh City - VN
 *School: Ha Tinh High School for the Gifted
**/
#include <bits/stdc++.h>
#define task "LAMP"
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
const int maxN = 1e6 + 9;
const int maxM = 3e3 + 11;
const int mod = 1e9 + 7;
const ll oo = 1e18;
const ll MOD = 998244353;
const ld PI = 4 * atan(1);
const double EPS = 1e-6;

ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
ll dxe[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll dye[] = {1, 1, 0, -1, -1, -1, 0, 1};

ll n, m, k, T;
ll color[maxM];
vector<ll> vt[maxM];
bool dp[maxM][2][2];

void DFS(int u, int vv)
{
    bool check = false;
    ll cnta(0), cntb(0), cnt_ab(0), cnta0(0), cnta1(0);
    bool checka = true, checkb = true;
    ll cnt_ab01(0);

    for (auto v : vt[u])
    {
        if (v == vv)
            continue;

        DFS(v, u);
        check = true;

        if (dp[v][0][1] == 1 && dp[v][1][1] == 1)
            cnt_ab++;
        else if (dp[v][0][1] == 1)
            cnta++;
        else if (dp[v][1][1] == 1)
            cntb++;
        else
            checka = false;
        if (dp[v][0][0] == 1 && dp[v][1][0] == 1)
            cnt_ab01++;
        else if (dp[v][0][0] == 1)
            cnta0++;
        else if (dp[v][1][0] == 1)
            cnta1++;
        else
            checkb = false;
    }

    if (!check)
    {
        dp[u][0][color[u]] = 1;
        dp[u][1][1 - color[u]] = 1;
    }
    else
    {
        if ((cntb % 2 == 0 || cnt_ab >= 1) && checka)
            dp[u][0][color[u]] = 1;
        if ((cntb % 2 == 1 || cnt_ab >= 1) && checka)
            dp[u][0][1 - color[u]] = 1;
        if ((cnta1 % 2 == 0 || cnt_ab01 >= 1) && checkb)
            dp[u][1][1 - color[u]] = 1;
        if ((cnta1 % 2 == 1 || cnt_ab01 >= 1) && checkb)
            dp[u][1][color[u]] = 1;
    }
}

vector<ll> vec;
void trace(int u, int vv, int idx, int idy)
{
    if (idx == 1)
    {
        vec.emplace_back(u);
    }
    if (!idx)
    {
        // a -> 0
        // b -> 1
        // ab -> 01
        vector<ll> cnta, cntb, cnt_ab;
        for (auto v : vt[u])
        {
            if (v == vv)
            {
                continue;
            }
            if (dp[v][0][1] == 1 && dp[v][1][1] == 1)
            {
                cnt_ab.emplace_back(v);
            }
            else if (dp[v][0][1] == 1)
            {
                cnta.emplace_back(v);
            }
            else if (dp[v][1][1] == 1)
            {
                cntb.emplace_back(v);
            }
        }
        if (color[u] == idy)
        {
            if (!(ll(cntb.size()) & 1))
            {
                for (auto v : cnta)
                {
                    trace(v, u, 0, 1);
                }
                for (auto v : cnt_ab)
                {
                    trace(v, u, 0, 1);
                }
                for (auto v : cntb)
                {
                    trace(v, u, 1, 1);
                }
            }
            else
            {
                for (auto v : cnta)
                {
                    trace(v, u, 0, 1);
                }
                for (int i(0); i < cnt_ab.size() - 1; i++)
                {
                    trace(cnt_ab[i], u, 0, 1);
                }
                trace(cnt_ab.back(), u, 1, 1);
                for (auto v : cntb)
                {
                    trace(v, u, 1, 1);
                }
            }
        }
        else
        {
            if ((ll(cntb.size())) & 1)
            {
                for (auto v : cnta)
                {
                    trace(v, u, 0, 1);
                }
                for (auto v : cnt_ab)
                {
                    trace(v, u, 0, 1);
                }
                for (auto v : cntb)
                {
                    trace(v, u, 1, 1);
                }
            }
            else
            {
                for (auto v : cnta)
                {
                    trace(v, u, 0, 1);
                }
                for (int i(0); i < cnt_ab.size() - 1; i++)
                {
                    trace(cnt_ab[i], u, 0, 1);
                }
                trace(cnt_ab.back(), u, 1, 1);
                for (auto v : cntb)
                {
                    trace(v, u, 1, 1);
                }
            }
        }
    }
    else
    {
        vector<ll> cnta, cntb, cnt_ab;
        for (auto v : vt[u])
        {
            if (v == vv)
            {
                continue;
            }
            if (dp[v][0][0] == 1 && dp[v][1][0] == 1)
            {
                cnt_ab.emplace_back(v);
            }
            else if (dp[v][0][0] == 1)
            {
                cnta.emplace_back(v);
            }
            else if (dp[v][1][0] == 1)
            {
                cntb.emplace_back(v);
            }
        }
        if (color[u] == 1 - idy)
        {
            if (!(ll(cntb.size()) & 1))
            {
                for (auto v : cnta)
                {
                    trace(v, u, 0, 0);
                }
                for (auto v : cnt_ab)
                {
                    trace(v, u, 0, 0);
                }
                for (auto v : cntb)
                {
                    trace(v, u, 1, 0);
                }
            }
            else
            {
                for (auto v : cnta)
                {
                    trace(v, u, 0, 0);
                }
                for (int i(0); i < cnt_ab.size() - 1; i++)
                {
                    trace(cnt_ab[i], u, 0, 0);
                }
                trace(cnt_ab.back(), u, 1, 0);
                for (auto v : cntb)
                {
                    trace(v, u, 1, 0);
                }
            }
        }
        else
        {
            if ((ll(cntb.size()) & 1))
            {
                for (auto v : cnta)
                {
                    trace(v, u, 0, 0);
                }
                for (auto v : cnt_ab)
                {
                    trace(v, u, 0, 0);
                }
                for (auto v : cntb)
                {
                    trace(v, u, 1, 0);
                }
            }
            else
            {
                for (auto v : cnta)
                {
                    trace(v, u, 0, 0);
                }
                for (int i(0); i < cnt_ab.size() - 1; i++)
                {
                    trace(cnt_ab[i], u, 0, 0);
                }
                trace(cnt_ab.back(), u, 1, 0);
                for (auto v : cntb)
                {
                    trace(v, u, 1, 0);
                }
            }
        }
    }
}

void progress()
{
    cin >> n >> T;
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        vt[u].emplace_back(v);
        vt[v].emplace_back(u);
    }
    for ( ; T--;)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            cin >> color[i];
        }
        vec.clear();
        DFS(1, -1);
        ll pos, idx, idy;
        if (dp[1][0][1] == 1)
        {
            pos = 1, idx = 0, idy = 1;
        }
        else if (dp[1][1][1] == 1)
        {
            pos = 1, idx = 1, idy = 1;
        }
        else
        {
            cout << -1 << '\n';
            continue;
        }
        trace(pos, -1, idx, idy);
        cout << vec.size() << " ";
        for (auto v : vec)
        {
            cout << v << " ";
        }
        cout << '\n';
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

