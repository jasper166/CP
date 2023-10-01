#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;
#define MAX 1005
#define INF 0x3f3f3f

// B19
int n, m;
ll f[MAX][MAX];
int a[MAX][MAX];

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    // f[1][1] = a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1)
                f[i][j] = a[i][j];
            else
                f[i][j] = a[i][j] + max(f[i][j - 1], f[i - 1][j]);
        }
    }

    cout << f[n][m] << "\n";

    return 0;
}

