/**
 *Author: Le Son - TK2._CHT
 *Spawn: 01/10/2006 - Ha Tinh City - VN
 *School: Ha Tinh High School for the Gifted
 **/
#include <bits/stdc++.h>
#define task "hexanet"
using namespace std;
typedef int64_t ll;
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
const int maxN = 31, K = 6;
const int maxM = 1e3 + 11;
const int mod = 1e9 + 7;
const ll oo = 1e18;
const ll MOD = 998244353;
const ld PI = 4 * atan(1);
const double EPS = 1e-6;

ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
ll dxe[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll dye[] = {1, 1, 0, -1, -1, -1, 0, 1};

const vector<ii> dxy = {
    {-1, 0},
    {-1, -1},
    {0, -1},
    {1, 0},
    {1, 1},
    {0, 1}
};

ll grid[2 * maxN + 1][2 * maxN + 1];
ll DD[2 * maxN + 1][2 * maxN + 1];
ii pos[3 * maxN * (maxN + 1) + 1];
vector<int> imp;
ll n, m, k;
ll dp[1 << K][1 + 3 * maxN * (maxN + 1)];

void fillGrid()
{
    grid[n][n] = 0;
    vector<ii> direction = {
        {1, 1},
        {1, 0},
        {0, -1},
        {-1, -1},
        {-1, 0}
    };
    int num = 0;
    pos[num++] = {n, n};
    int x = n - 1, y = n;
    for (int i = 1; i <= n; i++)
    {
        for (auto [ddx, ddy] : direction)
        {
            for (int j = 0; j < i; j++)
            {
                pos[num] = {x, y};
                grid[x][y] = num++;
                x += ddx, y += ddy;
            }
        }
        pos[num] = {x, y};
        grid[x][y] = num++;
        x--;
        if (x < 0) break;
        for (int j = 0; j < i; j++)
        {
            pos[num] = {x, y};
            grid[x][y] = num++;
            y++;
        }
    }
}

bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 2 * n + 1 && y < 2 * n + 1 && DD[x][y] != 0;
}

string binary(int n)
{
    string ans;
    for (int i = 0; i < 6; i++)
    {
        ans += char((n >> i & 1) + '0');
    }
    return ans;
}

ll solve()
{
    memset(dp, 0x3f, sizeof(dp));
    int M = 1 << (imp.size());
    for (int i = 0; i < int(imp.size()); i++)
    {
        auto [x, y] = pos[imp[i]];
        dp[1 << i][imp[i]] = DD[x][y];
    }

    int tmp = 3 * n * (n + 1) + 1;

    priority_queue<pair<ll, int>> pq;
    for (int mask = 1; mask < M; mask++)
    {
        for (int i = 0; i < tmp; i++)
        {
            auto [x, y] = pos[i];
            for (int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask)
            {
                dp[mask][i] = min(dp[mask][i], dp[submask][i] + dp[submask ^ mask][i] - DD[x][y]);
            }
        }

        for (int u = 0; u < tmp; u++)
        {
            if (dp[mask][u] >= oo) continue;
            pq.push({-dp[mask][u], u});
        }

        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            d = -d;
            if (d > dp[mask][u]) continue;
            auto [x, y] = pos[u];

            for (auto [dx, dy] : dxy)
            {
                int nx = x + dx, ny = y + dy;
                if (!valid(nx, ny)) continue;
                ll node = dp[mask][u] + DD[nx][ny];
                int v = grid[nx][ny];
                if (node < dp[mask][v])
                {
                    dp[mask][v] = node;
                    pq.push({-node, v});
                }
            }
        }
    }

    ll ans = oo;
    for (int i = 0; i < 3 * n * (n + 1) + 1; i++)
    {
        ans = min(ans, dp[M - 1][i]);
    }
    return ans;
}

void progress()
{
    memset(DD, 0, sizeof(DD));
    int phi;
    cin >> n >> phi;
    phi = 3 - phi;
    fillGrid();
    for (int i = 0; i < 6; i += phi)
    {
        imp.push_back(n * (n + 1) * 3 - i * n);
    }
    for (int i = 0; i < 3 * n * (n + 1) + 1; i++)
    {
        auto [x, y] = pos[i];
        cin >> DD[x][y];
    }
    cout << solve();
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

