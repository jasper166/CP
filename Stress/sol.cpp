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
int ans[N];
int cnt[N], f[N];
int prv[N], pt[N], px[N], py[N];

void add(int x) {
    f[cnt[x]]--;
    cnt[x]++;
    f[cnt[x]]++;
}
void del(int x) {
    f[cnt[x]]--;
    cnt[x]--;
    f[cnt[x]]++;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    cin >> n >> q >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    vector <Query> queries;
    vector <int> upds;
    for (int i = 1; i <= q; ++i) {
        cin >> pt[i] >> px[i] >> py[i];
        if (pt[i] == 2) queries.push_back({px[i], py[i], i});
        else upds.push_back(i);
    }

    sort(queries.begin(), queries.end());
    int l = 1, r = 0, t = -1;
    for (auto [L, R, id] : queries) {
        while (l > L) add(a[--l]);
        while (r < R) add(a[++r]);
        while (l < L) del(a[l++]);
        while (r > R) del(a[r--]);

        while (t + 1 < (int) upds.size() && upds[t + 1] < id) {
            ++t;
            int j = px[upds[t]];
            int nxt_val = py[upds[t]];
            debug(j, a[j], nxt_val);
            if (L <= j && j <= R) {
                del(a[j]);
                add(nxt_val);
            }
            prv[t] = a[j];
            a[j] = nxt_val;
        }

        while (t >= 0 && upds[t] > id) {
            int j = px[upds[t]];
            int lst_val = prv[t];
            if (L <= j && j <= R) {
                del(a[j]);
                add(lst_val);
            }
            a[j] = prv[t];
            --t;
        }
        
        // debug(cnt);
        // debug(f);
        ans[id] = f[k];
    }
    for (int i = 1; i <= q; ++i)
        if (pt[i] == 2)
            cout << ans[i] << "\n";
}

