 
#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using ii = pair <int, int>;
#define MAX 1005
#define INF 0x3f3f3f
const int MOD = 1e9 + 7;

int n, m;
int f[MAX][MAX];
// Canh hinh vuong lon nhat chua toan so 1 bao gom ca o(i, j);
int a[MAX][MAX];
// b19
signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = a[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1)
                f[i][j] = 1 + min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]});
            else
                f[i][j] = 0;
            res = max(res, f[i][j]);
        }
    }

    cout << res << "\n";
    return 0;
}