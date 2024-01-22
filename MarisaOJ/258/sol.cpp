#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int BLOCK = 450;
const int N = 1e5 + 5;
const int BASE = 31;

vector <ll> bl[BLOCK];
ll h[N], pw[N];
string s, t;
int n, q;

ll get(int l, int r) {
    if (l > r) return 0;
    return (h[r] - h[l - 1] * pw[r - l + 1]);
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> s >> q;
    int n = s.size();
    s = "@" + s;
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = (1LL * pw[i - 1] * BASE);
        h[i] = ((1LL * h[i - 1] * BASE) + (s[i] - 'a' + 1));
    }

    int sz = sqrt(n);
    for (int len = 1; len <= sz; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            ll x = get(i, i + len - 1);
            bl[len].push_back(x);
        }
        sort(bl[len].begin(), bl[len].end());
    }
   

    for (int _q = 1; _q <= q; ++_q) {
        cin >> t;
        
        int m = t.size();
        t = "@" + t;
        ll y = 0;
        for (int i = 1; i <= m; ++i)
            y = ((1LL * y * BASE) + (t[i] - 'a' + 1));
        int ans;
        if (m > sz) {
            ans = 0;
            for (int i = 1; i + m - 1 <= n; ++i)
                ans += (get(i, i + m - 1) == y);
        }
        else {
            int l = (int) (lower_bound(bl[m].begin(), bl[m].end(), y) - bl[m].begin());
            int r = (int) (upper_bound(bl[m].begin(), bl[m].end(), y) - bl[m].begin());
            // debug(l, r, m);
            ans = (r - l);
        }
        cout << ans << "\n";
    }
}

