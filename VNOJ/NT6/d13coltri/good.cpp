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
typedef pair<ll, ll> ii;
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

const ll maxN = 2e6 + 7;
ll n, m, k;
ll a[maxN];

void sieve()
{
    memset(a, 0, sizeof(a));
    a[0] = a[1] = 1;
    for (ll i = 2; i * i < maxN; i++)
    {
        if (a[i] == 0)
        {
            for (ll j = i; i * j < maxN; j++)
            {
                a[i * j] = 1;
            }
        }
    }
    for (ll i = 2; i < maxN; i += 2)
    {
        a[i] = 0;
    }
    for (ll i = 1; i < maxN; i++)
    {
        a[i] += a[i - 1];
    }
}
ll Ckn(ll n, ll k)
{
    if (n < k) return 0;
    ll t = 1;
    for (ll i = 0; i < k; i++)
    {
        t = t * (n - i) / (i + 1);
    }
    return t;
}
void progress()
{
    cin >> n;
    ll s1 = Ckn(n / 2, 3);
    ll s2 = Ckn(n - n / 2, 3);
    ll s3 = 0;
    for (ll i = 1; i <= n; i++)
    {
        s3 += Ckn(a[i + n] - a[i], 2);
    }
    cout << s1 + s2 + s3 << '\n';
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
    sieve();
    ll nt = 1;
    cin >> nt;
    for (; nt--;)
    {
        progress();
    }
}
/** LeSonnn_ **/
/** LCG **/

