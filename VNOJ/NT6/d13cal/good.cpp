#include <bits/stdc++.h>
#define task "aaa"
using namespace std;
typedef long long ll;

const int mod = 1e4 + 7;

ll f[21];

ll mul(ll x, ll y)
{
    return (x * y) % mod;
}

ll sub(ll x, ll y)
{
    return (x - y + mod * mod) % mod;
}

ll powd(ll x, ll y)
{
    if (!y)
        return 1;
    ll tmp = powd(x, y / 2);
    tmp = tmp * tmp % mod;
    if (y % 2)
        return tmp * x % mod;
    return tmp;
}

void progress()
{
    for (int n = 1; n <= 11; n++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    for (int x = 1; x <= n; x++)
                    {
                        for (int y = 1; y <= n; y++)
                        {
                            f[n] += abs(i - j) * abs(j - k) * abs(k - x) * abs(x - y) * abs(y - i);
                            f[n] %= mod;
                        }
                    }
                }
            }
        }
    }

    int n;
    while (cin >> n)
    {
        //cin >> n;
        if (!n) break;
        ll ans = 0;
        for (int i = 1; i <= 11; i++)
        {
            ll tmp = 1;
            for (int j = 1; j <= 11; j++)
            {
                if (j == i)
                {
                    continue;
                }
                tmp *= mul(sub(n, j), powd(sub(i, j), mod - 2));
                tmp %= mod;
            }
            ans = (ans + mul(f[i], tmp)) % mod;
        }
        cout << ans << '\n';
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

