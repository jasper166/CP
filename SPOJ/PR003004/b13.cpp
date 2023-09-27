#include <bits/stdc++.h>
using namespace std;
// #define int long long
using ll = long long;
using ii = pair <int, int>;
#define MAX 1005
#define INF 0x3f3f3f


int n;
int a[MAX];
int f[MAX]; // tang
int g[MAX]; // giam
// f(i):
// B13
int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        f[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + a[i]);
            }
        }
    }
    // i : f(1.. i) + g(i .. n);
    for (int i = n; i >= 1; i--) {
        g[i] = a[i];
        for (int j = n; j > i; j--) {
            if (a[i] > a[j]) {
                g[i] = max(g[i], g[j] + a[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i] + g[i] - a[i]);
    cout << ans << "\n";

    return 0;
}

