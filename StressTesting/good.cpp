#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int fac[N], inv[N];

int bPow(int a, int b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (1LL * ans * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return (int) ans;
}

int F[N];
void prepare() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = (1LL * fac[i - 1] * i) % MOD;

    inv[N - 1] = bPow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) inv[i] = (1LL * inv[i + 1] * (i + 1)) % MOD;

        F[0] = 1;
    for (int i = 1; i <= 50; ++i) F[i] = F[i - 1] * 1LL * i;
}


int a, b, n;

// Kiem tra so tot
bool isGood(int s) {
    while (s) {
        int d = s % 10;
        if (d != a && d != b) return 0;
        s /= 10;
    }
    return 1;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    prepare();

    cin >> a >> b >> n;
    if (a < b) swap(a, b);

    ll ans = 0;
    for (int s = n; s <= 9 * n; ++s) {
        if (isGood(s)) {
            /*
                So hien tai co x chu so a, y chu so b, do dai la n
                x + y = n;
                a * x + b * y = s;
                0 <= x, y;
            */
            int x = (s - b * n) / (a - b);
            int y = n - x;
            if (0 <= x && 0 <= y && a * x + b * y == s) {
                // Tim duoc cap x, y thoa man -> so luong so tu cap x, y la hoan vi lap
                // ans += ((1LL * fac[n] * inv[x]) % MOD * inv[y]) % MOD;
                // ans %= MOD;
                ans += (F[n] / (F[x] * F[y]));
            }
        }
    }

    cout << ans << "\n";
}