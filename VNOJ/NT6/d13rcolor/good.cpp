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
inline bool minimize(shark& a, const shark& b) { return (a > b ? (a = b), 1 : 0); }
template <class shark>
inline bool maximize(shark& a, const shark& b) { return (a < b ? (a = b), 1 : 0); }

// declare
const int maxN = 2e3 + 9;
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
int n, m;
string s[maxN];
bool check[maxN][maxN];

void cal(int x, int y)
{
        for (int t = 0; t < 2; t++)
        {
                bool shyn = true;
                for (int i = x; i <= x + 2; i++)
                {
                        for (int j = y + (((i - x) & 1) == t); j <= y + 2; j += 2)
                        {
                                if (i < 0 || j < 0 || i >= n || j >= m)continue;
                                shyn &= s[i][j] == '*';
                        }
                }
                if (!shyn)continue;
                for (int i = x; i <= x + 2; i++)
                {
                        for (int j = y + (((i - x) & 1) == t); j <= y + 2; j += 2)
                        {
                                if (i < 0 || j < 0 || i >= n || j >= m)continue;
                                check[i][j] = true;
                        }
                }
        }
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

        while (cin >> n >> m)
        {
                for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)check[i][j] = false;
                for (int i = 0; i < n; i++)cin >> s[i];
                for (int i = -1; i < n + 1; i++)
                {
                        for (int j = -1; j < m + 1; j++)
                        {
                                cal(i, j);
                        }
                }

                bool res = true;

                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < m; j++)
                        {
                                if (s[i][j] == '*')res &= check[i][j];
                        }
                }

                cout << (res ? "YES" : "NO") << "\n";
        }
}
/** LeSonnn_ **/
/** LCG **/

