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

// max - min
template <class shark>
inline bool minimize(shark &a, const shark &b) { return (a > b ? (a = b), 1 : 0); }
template <class shark>
inline bool maximize(shark &a, const shark &b) { return (a < b ? (a = b), 1 : 0); }

// declare
const int maxN = 1e6 + 9;
const int maxM = 1e3 + 11;
const int maxK = 5e2 + 3;
const int mod = 1e9 + 7;
const ll oo = 1e18;
const ll MOD = 998244353;
const ld PI = 4 * atan(1);
const double EPS = 1e-6;

ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
ll dxe[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll dye[] = {1, 1, 0, -1, -1, -1, 0, 1};

ll n, m, k;
ll a[maxK][maxK], row[maxK][maxK], col[maxK][maxK], dp[maxK][maxK][2][2];

bool Calc(int i, int j, bool type, bool val)
{
    if (dp[i][j][type][val] != -1)
    {
        return dp[i][j][type][val];
    }
    if (!i || !j) return 0;
    dp[i][j][type][val] = 0;
    bool nxt = val;
    if (type) nxt ^= (row[i][j] & 1);
    else nxt ^= (col[j][i] & 1);
    int x = i, y = j;
    if (type) x--;
    else y--;
    if (!nxt && !Calc(x, y, 0, 0) && !Calc(x, y, 1, 0))
    {
        dp[i][j][type][val] = 1;
        return true;
    }
    dp[i][j][type][val] = Calc(x, y, type, nxt);
    return dp[i][j][type][val];
}

void progress()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            row[i][j] = row[i][j - 1] + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            col[i][j] = col[i][j - 1] + a[j][i];
        }
    }

    memset(dp, -1, sizeof(dp));
    if (Calc(m, n, 1, 0) || Calc(m, n, 0, 0))
    {
        cout << "TRUE";
        return;
    }
    cout << "FALSE";
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

