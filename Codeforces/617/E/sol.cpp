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
const int X = 2e6 + 5;
const int BLOCK = 311;

struct Queries {
    int l, r, id;
    bool operator < (const Queries ot) const {
        if (l / BLOCK == ot.l / BLOCK)
            return (l / BLOCK & 1)? r > ot.r : r < ot.r;
        else 
            return (l / BLOCK < ot.l / BLOCK);
    }
} qs[N];

int n ,q, k;
int cnt[X];
int a[N], p[N];
ll ret, ans[N];
int l, r;

void add(int i) {
    int x = p[i];
    ret += cnt[k ^ x];
    ++cnt[x];
}
void del(int i) {
    int x = p[i];
    --cnt[x];
    ret -= (cnt[k ^ x]);
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> q >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) p[i] = p[i - 1] ^ a[i];

    for (int i = 1; i <= q; ++i) {
        int lx, rx; cin >> lx >> rx;
        --lx;
        qs[i] = {lx, rx, i};
    }
    
    sort(qs + 1, qs + 1 + q);
    l = 1, r = 0;
    for (int i = 1; i <= q; ++i) {
        auto [L, R, id] = qs[i];
        while (l > L) add(--l);
        while (r < R) add(++r);
        while (l < L) del(l++);
        while (r > R) del(r--);
        ans[id] = ret;
    }
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
}


