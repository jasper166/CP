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
const int maxN = 1e6 + 9;
ll n, m, k, p;
ll t[maxN], a[maxN];
ll best[maxN], pk[maxN];

void progress()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int64_t res(0);
    memset(best, 0, sizeof(best));
    for(int i = 1; i <= n; i++)
    {
        p += a[i];
        pk[t[i]] += a[i];
        int l = i == n ? 1 : t[i + 1], r = i == n ? k : t[i + 1];
        for(int j = l; j <= r; j++)
        {
            res = max<int64_t>(res, p - 1ll * k * pk[j] + best[j]);
        }
        best[t[i]] = max<int64_t>(best[t[i]], -p + 1ll * k * pk[t[i]]);
    }
    cout << res;
}

signed main()
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
    for ( ; nt--;)
    {
        progress();
    }
}

