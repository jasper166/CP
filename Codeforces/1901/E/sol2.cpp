#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define fi first
#define se second
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Fenwick {
    vector <int> f;
    Fenwick() : f(N + 5, 0) {};
    void upd(int x, int val) {
        for (; x < N; x += x & -x)
            f[x] += val;
    }
    int qry(int x) {
        int ans = 0;
        for (; x; x -= x & -x)
            ans += f[x];
        return ans;
    }
};

int n, x;
int a[N], b[N];
void run_case() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> c;
    vector <pii> d;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        c.push_back(b[i]);
        d.push_back({a[i], i});
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    int cnt = x + 1;
    int p = n - 1;
    --x;

    while (x >= 0) {
        b[d[p].se] = c[x];
        --x;
        --p;
    }

    x = n - 1;
    while (p >= 0) {
        b[d[p].se] = c[x];
        --x;
        --p;
    }

    for (int i = 0; i < n; ++i)
        if (b[i] < a[i])
            --cnt;

    cout << cnt << "\n";
    if (cnt) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
    cout << "\n";

}



signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
