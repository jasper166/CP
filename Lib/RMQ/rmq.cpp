#include "bits/stdc++.h"
#include <climits>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const ll LINF = 1e18 + 5;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int LOG = 18;

int n, q;
int a[MAX];
int f[LOG][MAX];
int lg[MAX];

int get(int l, int r) {
    int k = lg[r - l + 1];
    return min(f[k][l], f[k][r - (1 << k) + 1]);
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) f[0][i] = a[i];
    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

    for (int k = 1; k <= log2(n); k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            f[k][i] = min(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
        }
    } 
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        cout << get(l, r) << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    // cin >> Test;

    for (int test = 1; test <= Test; test++){
        run_case();
    }
}
