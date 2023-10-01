#include <bits/stdc++.h>
#define task "a"
//#define int int64_t
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int f[100];

void progress()
{
    vector<int> prime;
    for (int i = 1; i <= 70; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                cnt++;
        }
        if (cnt == 2)
            prime.push_back(i);
    }
    for (int i = 1; i <= 70; i++)
    {
        for (int j = 0; j < prime.size(); j++)
        {
            int tmp = i, cnt = 0;
            while (tmp % prime[j] == 0)
                cnt++, tmp /= prime[j];
            if (cnt & 1)
                f[i] |= (1 << j);
        }
    }
    int n;
    cin >> n;
    vector<int> v;
    int ans = 1;
    while (n--)
    {
        int k;
        cin >> k;
        k = f[k];
        for (auto it : v)
            k = min(k, k ^ it);
        if (k)
            v.push_back(k);
        else
            ans = ans * 2 % mod;
    }
    cout << ans - 1;
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

