#include "bits/stdc++.h"
#include <numeric>
// @Jasper
using namespace std;
using ll = long long;

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int count(int x, int y[], int n, int a[]) {
    if (x == 0)
        return 0;
    if (x == 1)
        return a[0];
    int it = upper_bound(y, y + n, x) - y;
    int ans = n - it;
    ans += (a[0] + a[1]);
    if (x == 2)
        ans -= (a[3] + a[4]);
    if (x == 3)
        ans += a[2];
    return ans;
}

void testCase() {
    int n, m;
    cin >> n >> m;
    int x[n], y[m], a[5] = {}, ans = 0;
    for (int i = 0; i < n; i++)
            cin >> x[i];
    for (int i = 0; i < m; i++)
        cin >> y[i];
    for (int i = 0; i < n; i++) {
        if (y[i] < 5)
            a[y[i]]++;
    }
    sort(y, y + n);
    for (int i = 0; i < m; i++) {
        ans += count(x[i], y, n, a);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);

    int T = 1; 
    cin >> T;
    while (T--) {
        testCase();
        cout << "\n";
    }
    return 0;
}
