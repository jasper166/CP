#include <bits/stdc++.h>
#define task "table"
using namespace std;
typedef long long ll;
const int maxN = 1e3 + 11;
const int maxM = 51;
const ll mod = 111539786;
ll n, m, k;
ll b[maxM][maxM];
vector<int> a[maxN];

int get_id(int i, int j)
{
    return (i - 1) * n + j;
}

void add(vector<int> &x, vector<int> y, int mul)
{
    for (int i = 0; i <= m * n; i++)
    {
        x[i] = (x[i] + y[i] * mul) % 3;
    }
}

void progress()
{
    cin >> m >> n;
    for (int i = 1; i <= m * n; i++)
    {
        a[i] = vector<int>(m * n + 5, 0);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> b[i][j];
            if (i > 1)
                a[get_id(i, j)][get_id(i - 1, j)] = 1;
            if (i < m)
                a[get_id(i, j)][get_id(i + 1, j)] = 1;
            if (j > 1)
                a[get_id(i, j)][get_id(i, j - 1)] = 1;
            if (j < n)
                a[get_id(i, j)][get_id(i, j + 1)] = 1;
            a[get_id(i, j)][0] = b[i][j];
        }
    }

    ll ans(1);
    for (int i = 1; i <= m * n; i++)
    {
        bool flag = false;
        for (int j = 1; j <= m * n; j++)
        {
            if (a[i][j])
            {
                for (int k = i + 1; k <= m * n; k++)
                {
                    if (a[k][j])
                    {
                        add(a[k], a[i], (a[i][j] == a[k][j]) + 1);
                    }
                }
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            if (a[i][0])
            {
                cout << 0;
                return;
            }
            ans = (ans * 3) % mod;
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

