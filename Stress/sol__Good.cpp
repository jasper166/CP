#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int BLOCK = 331;
const int N = 1e5 + 5;

// Mo's update
struct Query {
    int l, r, id;
    bool operator < (const Query ot) const {
        if (l / BLOCK != ot.l / BLOCK) return l < ot.l;
        if (r / BLOCK != ot.r / BLOCK) return r < ot.r;
        return id < ot.id;
    } 
};

int n, q, k;
int a[N];
int prv[N], pt[N], px[N], py[N];

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> q >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= q; ++i) {
        cin >> pt[i] >> px[i] >> py[i];
        if (pt[i] == 2) {
            map <int, int> cnt;
            int ans = 0;
            for (int j = px[i]; j <= py[i]; ++j)
                cnt[a[j]]++;
            for (auto [x, cx] : cnt)
                ans += (cx == k);
            cout << ans << "\n";
        }
        else {
            a[px[i]] = py[i];
        }
    }

    
}

