 
#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using ii = pair <int, int>;
#define MAX 1005
#define INF 0x3f3f3f
const int MOD = 1e9 + 7;

int n;
int f[MAX][MAX];
char a[MAX][MAX];
// b19
signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    if (a[1][1] == '*' || a[n][n] == '*') {
        cout << "0\n";
        return 0;
    }

    f[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1)
                continue;

            if (a[i][j] == '*')
                f[i][j] = 0;
            else
                f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD; 
        }
    }

    cout << f[n][n] << "\n"; 

    return 0;
}