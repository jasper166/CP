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

int n, q;
ll blk[BLOCK][BLOCK];
ll lzy[BLOCK];
ll a[N];


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i)
        blk[i / BLOCK][i % BLOCK] = a[i];
    for (int i = 0; i <= n / BLOCK; ++i)
        sort(blk[i], blk[i] + BLOCK);

    for (int _i = 1; _i <= q; ++_i) {
        int cmd, l, r, x;
        cin >> cmd;
        if (cmd == 1) {
            cin >> l >> r >> x;
            int L = l / BLOCK, R = r / BLOCK;
            if (L == R) {
                for (int i = l; i <= r; ++i)
                    a[i] += x;
                for (int i = L * BLOCK; i < (L + 1) * BLOCK; ++i)
                    blk[L][i % BLOCK] = a[i];
                sort(blk[L], blk[L] + BLOCK);
            } 
            else {
                for (int i = l; i < (L + 1) * BLOCK; ++i)
                    a[i] += x;
                for (int i = L * BLOCK; i < (L + 1) * BLOCK; ++i)
                    blk[L][i % BLOCK] = a[i];
                sort(blk[L], blk[L] + BLOCK);

                for (int i = R * BLOCK; i <= r; ++i)
                    a[i] += x;
                for (int i = R * BLOCK; i < (R + 1) * BLOCK; ++i)
                    blk[R][i % BLOCK] = a[i];
                sort(blk[R], blk[R] + BLOCK);

                for (int i = L + 1; i < R; ++i)
                    lzy[i] += x;
            }
        }
        else {

            cin >> x;
            int L = -1, R = -1;
            for (int i = 0; i <= n / BLOCK; ++i) {
                if (binary_search(blk[i], blk[i] + BLOCK, x - lzy[i])) {
                    L = i;
                    break;
                }
            }

            for (int i = n / BLOCK; i >= 0; --i) {
                if (binary_search(blk[i], blk[i] + BLOCK, x - lzy[i])) {
                    R = i;
                    break;
                }
            }

            if (L == -1 || R == -1) {
                cout << "-1\n";
                continue;
            }

            for (int i = max(1, L * BLOCK); i <= min(n, (L + 1) * BLOCK - 1); ++i) {
                // debug(i, a[i]);
                if (a[i] + lzy[L] == x) {
                    l = i;
                    break;
                }
            }

            for (int i = min(n, (R + 1) * BLOCK - 1); i >= max(1, R * BLOCK); --i) {
                if (a[i] + lzy[R] == x) {
                    r = i;
                    break;
                }
            }
            // debug(l, r, L, R);
            // for (int i = 1; i <= n; ++i) {
            //     debug(a[i]);
            // }
            cout << (r - l) << "\n";
        }
    }
}


