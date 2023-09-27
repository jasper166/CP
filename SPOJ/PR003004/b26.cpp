#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;
#define MAX 1005
#define INF 0x3f3f3f


int n;
int a[MAX][MAX];
int f[MAX][MAX];
// f(i, j):
// B26
int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        f[1][i] = a[1][i];

    // (j - 1) => j;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                f[i][j] = a[i][j] + max(f[i - 1][j], f[i - 1][j + 1]);
            }
            else if (j == n) {
                f[i][j] = a[i][j] + max(f[i - 1][j], f[i - 1][j - 1]);
            }
            else {
                f[i][j] = a[i][j] + max({f[i - 1][j + 1], f[i - 1][j], f[i - 1][j - 1]});
            }
        }
    }

    int ans = -INF;

    for (int i = 1; i <= n; i++)
        ans = max(ans, f[n][i]);
    cout << ans << "\n";

    return 0;
}

