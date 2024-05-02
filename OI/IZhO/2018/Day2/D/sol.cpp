#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int BLOCK = 6500;
const int B = 31;
const int N = 2e5 + 5;

template <typename T>
struct RangeMultiset {
    using P = pair <T, T>;

    multiset <P> st;
    vector <array <T, 3>> save;
    P seg[N];
    vector <P> bL[B], bR[B];
    T mx[B], mn[B];
    // divide BLOCK by length, keep them sorted by border
    int sz = 0;

    void build() {
        // debug(st);
        // debug(save);
        save.clear();
        for (int i = 0; i < B; ++i) {
            bL[i].clear(); bR[i].clear(); 
            mx[i] = 0; mn[i] = 2e9;
        }

        vector <array <T, 3>> p;
        for (auto [l, r] : st) {
            T len = r - l + 1;
            p.push_back({len, l, r});
        }

        sort(p.begin(), p.end());
        for (int i = 0; i < (int) p.size(); ++i) {
            auto [len, l, r] = p[i];
            bL[i / BLOCK].push_back({l, len});
            bR[i / BLOCK].push_back({r, len});
            mx[i / BLOCK] = max(mx[i / BLOCK], len);
            mn[i / BLOCK] = min(mn[i / BLOCK], len);
        }

        for (int i = 0; i < B; ++i) {
            sort(bL[i].begin(), bL[i].end());
            sort(bR[i].begin(), bR[i].end());
        }
    }

    void add(T l, T r) {
        seg[++sz] = make_pair(l, r);
        st.insert(make_pair(l, r));
        save.push_back({l, r, 1});
    }

    void del(T id) {
        st.erase(seg[id]);
        save.push_back({seg[id].first, seg[id].second, -1});
    }

    T qry(T l, T r, T k) {
        // qryA(k): numbers of segments have length >= k
        // qryR(k, L): numbers of segments have length >= k, right border < L
        // qryL(k, R): numbers of segments have length >= k, left border > R
        // brute-force for unproccesed ranges. O(sqrt(N))
        auto qryA = [&] (T k) -> T{
            T res = 0;
            for (int i = 0; i < B; ++i) {
                // if (max_len < k) -> bad block;
                // if (min_len >= k) take whole;
                if (mx[i] < k) continue;
                if (mn[i] >= k) {
                    res += bL[i].size();
                    continue;   
                }

                for (auto [x, len] : bL[i])
                    res += (len >= k);
            }
            return res;
        };

        auto qryR = [&] (T k, T L) -> T{
            T res = 0;
            for (int i = 0; i < B; ++i) {
                if (mx[i] < k) continue;
                if (mn[i] >= k) {
                    P x = make_pair(L, 0);
                    // < x -> lb - 1
                    auto it = lower_bound(bR[i].begin(), bR[i].end(), x);
                    int w = (int) (it - bR[i].begin());
                    res += w; 
                    continue;
                }

                for (auto [r, len] : bR[i]) {
                    res += (len >= k && r < L);
                }
            }
            return res;
        };

        auto qryL = [&] (T k, T R) -> T{
            T res = 0;
            for (int i = 0; i < B; ++i) {
                if (mx[i] < k) continue;
                if (mn[i] >= k) {
                    P x = make_pair(R, 2e9);
                    // > x -> sz - ub
                    auto it = upper_bound(bL[i].begin(), bL[i].end(), x);
                    int w = (int) (it - bL[i].begin());
                    res += (int) (bL[i].size()) - w;
                    continue;
                }
                for (auto [l, len] : bL[i])
                    res += (len >= k && l > R);
            }
            return res;
        };

        T res = 0;
        if (r - l + 1 < k)
            return 0;
        int QA = qryA(k);
        int QL = qryL(k, r - k + 1);
        int QR = qryR(k, l + k - 1);
        // debug(QA, QL, QR, k);
        res += QA - QL - QR;    
        for (auto& [L, R, w] : save) {
            if (R < l + k - 1) continue;
            if (L > r - k + 1) continue;
            if (R - L + 1 < k) continue;
            res += w;
        }
        return res;
    }
};

int n, t;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif
    

    cin >> n >> t;

    int lastans = 0;
    RangeMultiset <int> rst;

    for (int i = 0; i < n; ++i) {
        int cmd; cin >> cmd;
        if (i % BLOCK == 0) {
            rst.build();
        }
        if (cmd == 1) {
            int l, r; 
            cin >> l >> r;
            l = (l ^ (t * lastans));
            r = (r ^ (t * lastans));    
            if (l > r) swap(l, r);
            rst.add(l, r);
        }
        else if (cmd == 2) {
            int id; cin >> id;
            rst.del(id);
        }
        else {
            int l, r, k; cin >> l >> r >> k;
            l = (l ^ (t * lastans));
            r = (r ^ (t * lastans));
            if (l > r) swap(l, r);
            int ans = rst.qry(l, r, k);
            cout << ans << "\n";

            lastans = ans;
        }
    }
}


