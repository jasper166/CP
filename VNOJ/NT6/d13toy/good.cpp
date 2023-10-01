#include <bits/stdc++.h>
#define task "toy"
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int maxN = 1e5 + 11;
ll n, m, k;
ll l[maxN][2], r[maxN][2];
pair<ll, ll> a[maxN];

void progress()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    l[0][0] = LLONG_MAX, l[0][1] = LLONG_MIN;
    r[n + 1][0] = LLONG_MAX, r[n + 1][1] = LLONG_MIN;
    l[1][0] = l[1][1] = a[1].se;
    r[n][0] = r[n][1] = a[n].se;
    for (int i = 2; i <= n; i++)
    {
        l[i][0] = min(l[i - 1][0], a[i].se);
        l[i][1] = max(l[i - 1][1], a[i].se);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        r[i][0] = min(r[i + 1][0], a[i].se);
        r[i][1] = max(r[i + 1][1], a[i].se);
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == 1 && j == n)
            {
                break;
            }
            ans = min(ans, a[j].fi - a[i].fi + max(l[i - 1][1], r[j + 1][1]) - min(l[i - 1][0], r[j + 1][0]));
        }
    }
    cout << ans;
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

