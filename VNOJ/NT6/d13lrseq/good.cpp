#include <bits/stdc++.h>
#define task "lrseq"
using namespace std;
typedef long long ll;

const int maxN = 5e5 + 5;
ll n, L, R, a[maxN], s[maxN], st[maxN][22];

void progress()
{
    cin >> n >> L >> R;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        st[i][0] = s[i];
    }
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 0; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    ll ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        int l = i - R, r = i - L;
        if (r < 0)
        {
            continue;
        }
        l = max(l, 0);
        int j = __lg(r - l + 1);
        ll val = min(st[l][j], st[r - (1 << j) + 1][j]);
        ans = max(ans, s[i] - val);
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

