#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif

// #define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 105;
const int BLOCK = 350;

int n, m, q;
int a[MAX];
int ans[MAX];
deque <int> idx[MAX];
multiset <int> st;

struct Query {
    int l, r, id;
    bool operator < (const Query &o) const {
        if (l / BLOCK == o.l / BLOCK)
            return (l / BLOCK) & 1? r > o.r : r < o.r;
        return (l / BLOCK < o.l / BLOCK);
    }
} que[MAX];


void add(int id, int cmd) {
    int x = a[id];
    if (idx[x].size() >= 2) {
        int len = idx[x].back() - idx[x].front();
        st.erase(st.find(len));
    }
    if (cmd == 1)
        idx[x].push_front(id);
    if (cmd == 2)
        idx[x].push_back(id);

    if (idx[x].size() >= 2) {
        int len = idx[x].back() - idx[x].front();
        st.insert(len);
    }

}


void del(int id, int cmd) {
    int x = a[id];
    if (idx[x].size() >= 2) {
        int len = idx[x].back() - idx[x].front();
        st.erase(st.find(len));
    }
    if (!idx[x].empty() && cmd == 1)
        idx[x].pop_front();
    if (!idx[x].empty() && cmd == 2)
        idx[x].pop_back();

    if (idx[x].size() >= 2) {
        int len = idx[x].back() - idx[x].front();
        st.insert(len);
    }
}


int get() {
    if (!st.empty())
        return (*st.rbegin());
    return 0;
}

void run_case() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // idx[a[0]].push_front(0);
    for (int i = 1; i <= q; i++) {
        cin >> que[i].l >> que[i].r;
        if (que[i].l > que[i].r)
            swap(que[i].l, que[i].r);
        // que[i].r++;
        que[i].id = i;
    }

    sort(que + 1, que + 1 + q);
    int l = 0, r = 0;
    for (int i = 1; i <= q; ++i) {
        // debug(que[i].l, que[i].r);
        while (l > que[i].l) add(--l, 1);
        while (r < que[i].r) add(++r, 2);
        while (l < que[i].l) del(l++, 1);
        while (r > que[i].r) del(r--, 2);

        ans[que[i].id] = get();
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

