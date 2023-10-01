#include <bits/stdc++.h>
#define task "ods"
using namespace std;
typedef long long ll;

ll powd(ll a)
{
    return a * a;
}

ll cal(ll a)
{
    if (!a) return 0;
    if (a & 1)
        return (powd((a + 1) / 2) + cal(a / 2));
    else
        return powd(a / 2) + cal(a / 2);
}

void progress()
{
    ll x, y;
    cin >> x >> y;
    cout << cal(y) - cal(x - 1);
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
    cin >> nt;
    for (; nt--;)
    {
        progress();
        cout << '\n';
    }
}
/** LeSonnn_ **/
/** LCG **/

