#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = 1e5 + 5;
const int BLOCK = 331;

struct Queries {
    int l, r, id, x;
    bool operator < (const Queries ot) const {
        if (l / BLOCK == ot.l / BLOCK)
            return (l / BLOCK & 1)? r < ot.r : r > ot.r;
        else 
            return (l / BLOCK < ot.l / BLOCK);
    }
} qs[N];

int n, q;
int cnt[N], f[N];
int a[N], p[N];
int ans[N];

void add(int i) {
    f[cnt[a[i]]]--;
    cnt[a[i]]++;
    f[cnt[a[i]]]++;
}
void del(int i) {
    f[cnt[a[i]]]--;
    cnt[a[i]]--;
    f[cnt[a[i]]]++;
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    #ifdef JASPER
    	freopen("in1", "r", stdin);
    #endif
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= q; ++i) {
        int lx, rx, x; 
        cin >> lx >> rx >> x;
        qs[i] = {lx, rx, i, x};
    }
    
    sort(qs + 1, qs + 1 + q);
    int l = 1, r = 0;
    for (int i = 1; i <= q; ++i) {
        auto [L, R, id, x] = qs[i];
        while (l > L) add(--l);
        while (r < R) add(++r);
        while (l < L) del(l++);
        while (r > R) del(r--);
        ans[id] = f[x];
    }
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
}


