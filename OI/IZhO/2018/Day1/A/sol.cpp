#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
const ll INF = 1e18;

vector <vector <int>> rect;
int n, q;
ll ans;
// Counting needed white cells for coloring the rectangle (1, 1) -> (x, y) at pattern 1:
// W B W B..
// B W B W..
ll cal(int x, int y, int k) {
    ll res = 0;
    int lb_x = (x / k) * k, lb_y = (y / k) * k;
    if ((lb_x / k + lb_y / k) & 1) {
        // if current cell is in B block
        res += 1LL * ((lb_x / k) * (lb_y / k) / 2) * (k * k); 
        res += 1LL * (((lb_y / k) + 1) / 2) * k * (x - lb_x);
        res += 1LL * (((lb_x / k) + 1) / 2) * k * (y - lb_y);
    }
    else {
        // if current cell is in W block
        res += 1LL * ((lb_x / k) / 2) * (y - lb_y) * k;
        res += 1LL * ((lb_y / k) / 2) * (x - lb_x) * k;
        res += 1LL * (x - lb_x) * (y - lb_y);
        res += 1LL * (((lb_x / k) * (lb_y / k) + 1) / 2) * (k * k);
    }
    return res;
}

ll count(int x, int y, int X, int Y, int k) {
    return cal(X, Y, k) + cal(x - 1, y - 1, k) - cal(X, y - 1, k) - cal(x - 1, Y, k);
}

void solve(int k) {
    ll tot = 1LL * n * n;
    ll cur = tot - cal(n, n, k);
    // answer for pattern 1 -> pattern 2 : n * n - cnt;
    for (auto i : rect) {
        int x = i[0], y = i[1], X = i[2], Y = i[3];
        ll cnt = count(x, y, X, Y, k);
        // white cells needed for the rectangle (x, y) -> (X, Y);
        cur += cnt;
        // subtract already black cells;
        cur -= 1LL * (X - x + 1) * (Y - y + 1) - cnt;
    } 
    ans = min({ans, cur, 1LL * n * n - cur});
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
        int x, y, X, Y;
        cin >> x >> y >> X >> Y;
        rect.push_back({x, y, X, Y});
    }

    ans = INF;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            solve(i);
            if (i != n / i && i > 1)
                solve(n / i);
        }
    }
    cout << ans << "\n";
}


