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

int n, q;
deque <int> dq[BLOCK];
vector <int> cnt[BLOCK];
int a[N];

void shift(int l, int r) {
    int L = l / BLOCK, li = l % BLOCK;
    int R = r / BLOCK, ri = r % BLOCK;
    // debug(L, R, li, ri);
    int lst = dq[R][ri];
    dq[R].erase(dq[R].begin() + ri);
    cnt[R][lst]--;
    dq[L].insert(dq[L].begin() + li, lst);
    cnt[L][lst]++;
    for (int i = L; i < R; ++i) {
        lst = dq[i].back();
        dq[i].pop_back();
        cnt[i][lst]--;
        dq[i + 1].push_front(lst);
        cnt[i + 1][lst]++;
    }    
}

int solve(int l, int r, int k) {
    int L = l / BLOCK, li = l % BLOCK;
    int R = r / BLOCK, ri = r % BLOCK;
    int ans = 0;
    if (L == R) {
        for (int i = li; i <= ri; ++i)
            if (dq[L][i] == k) ++ans;
    }
    else {
        for (int i = li; i < (int) dq[L].size(); ++i)
            if (dq[L][i] == k) ++ans;
        for (int i = 0; i <= ri; ++i)
            if (dq[R][i] == k) ++ans;
        for (int i = L + 1; i < R; ++i)
            ans += cnt[i][k];
    }
    return ans;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i <= n / BLOCK; ++i) cnt[i].resize(1e5 + 5);
    for (int i = 0; i < n; ++i) {
        dq[i / BLOCK].push_back(a[i]);
        cnt[i / BLOCK][a[i]]++;
    }

    cin >> q;
    int ans = 0;
    for (int _q = 1; _q <= q; ++_q) {
        int cmd, l, r, k;
        cin >> cmd >> l >> r;
        l = (l + ans - 1) % n + 1;
        r = (r + ans - 1) % n + 1;      
        if (l > r) swap(l, r);

        // debug(l, r);
        if (cmd == 1) {
            shift(l - 1, r - 1);
        }
        else {
            cin >> k;
            k = (k + ans - 1) % n + 1;
            // debug(l, r, k);
            ans = solve(l - 1, r - 1, k);      
            cout << ans << "\n";
        }
    }
}


