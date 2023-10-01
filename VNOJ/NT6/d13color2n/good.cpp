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
#define bit(mask,i) ((mask>>i)&1)

// max - min
template <class shark>
inline bool minimize(shark& a, const shark& b) { return (a > b ? (a = b), 1 : 0); }
template <class shark>
inline bool maximize(shark& a, const shark& b) { return (a < b ? (a = b), 1 : 0); }
// declare
const int maxN = 1e3 + 9;
const int maxM = 1e3 + 11;
const int mod = 1e9 + 7;
const ll oo = 1e18;
const ll MOD = 998244353;
const ld PI = 4 * atan(1);
const double EPS = 1e-6;

ll dx[] = { 0, 1, 0, -1 };
ll dy[] = { -1, 0, 1, 0 };
ll dxe[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
ll dye[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

// main
int n, k, dp[maxN][2 * maxN][4];

int cal(int mask1, int mask2)
{
        if (bit(mask1, 0) == bit(mask1, 1))
        {
                if (bit(mask2, 0) == bit(mask1, 0) || bit(mask2, 1) == bit(mask1, 0)) return 0;
                return 1;
        }
        return (bit(mask1, 0) != bit(mask2, 0)) + (bit(mask1, 1) != bit(mask2, 1));
}

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

        cin >> n >> k;

        dp[1][1][0] = dp[1][2][1] = dp[1][2][2] = dp[1][1][3] = 1;

        for (int i = 2; i <= n; i++)
        {
                for (int mask1 = 0; mask1 < 4; mask1++)
                {
                        for (int mask2 = 0; mask2 < 4; mask2++)
                        {
                                int cnt = cal(mask1, mask2);
                                for (int j = cnt; j <= k; j++)
                                {
                                        dp[i][j][mask1] += dp[i - 1][j - cnt][mask2];
                                        dp[i][j][mask1] %= mod;
                                }
                        }
                }
        }

        int res = 0;
        for (int mask = 0; mask < 4; mask++)(res += dp[n][k][mask]) %= mod;
        cout << res;
      
}
/** LeSonnn_ **/
/** LCG **/
/*

*/

