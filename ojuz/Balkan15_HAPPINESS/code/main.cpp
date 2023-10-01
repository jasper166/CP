#include "bits/stdc++.h"
#include "happiness.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const ll LINF = 1e12 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

struct DynamicSegmentTree {
    struct Node {
        ll lx, rx, val;
        Node *l, *r;
        Node(ll _lx, ll _rx) {
            lx = _lx;
            rx = _rx;
            l = r = NULL;
        }
    };
    Node *p;
    void rmk(ll l, ll r) {
        p = new Node(l, r);
    }

    void upd(Node *root, ll pos, ll val) {
        if (root == NULL)
            return;
        root->val += val;
        if (root->lx != root->rx) {
            ll m = (root->lx + root->rx) >> 1ll;
            if (pos <= m) {
                if (root->l == NULL)
                    root->l = new Node(root->lx, m);
                upd(root->l, pos, val);
            }
            else {
                if (root->r == NULL)
                    root->r = new Node(m + 1, root->rx);
                upd(root->r, pos, val);
            }
        }
    }

    ll qry(Node *root, ll l, ll r) {
        if (root->lx > r || root->rx < l || root == NULL)
            return 0;
        if (l <= root->lx && root->rx <= r)
            return root->val;
        ll ans = 0;
        if (root->l != NULL)
            ans += qry(root->l, l, r);
        if (root->r != NULL)
            ans += qry(root->r, l, r);
        return ans;
    }

    ll check() {
        ll ai = 1, lim = p->val;
        while (ai < lim) {
            ll sum = qry(p, 1, ai);
            if (sum < ai)
                return 0;
            ai = sum + 1;
        }
        return 1;
    }
};
ll n, m, q;
DynamicSegmentTree st;

bool init(int coinsCount, ll maxCoinSize, ll coins[]) {
    st.rmk(1, maxCoinSize);
    sort(coins, coins + coinsCount);

    for (int i = 0; i < coinsCount; ++i)
        st.upd(st.p, coins[i], coins[i]);
    return st.check();
}

bool is_happy(int event, int coinsCount, ll coins[]) {
    for (int i = 0; i < coinsCount; ++i)
        st.upd(st.p, coins[i], 1ll * event * coins[i]);
    return st.check();
}

//void run_case() {
//    cin >> n >> m;
//    for (int i = 1; i <= n; ++i)
//        cin >> a[i];
//
//    DynamicSegmentTree st(1, m);
//    for (int i = 1; i <= n; ++i)
//        st.upd(st.p, a[i], a[i]);
//    cout << st.check() << "\n";
//
//    cin >> q;
//    while (q--) {
//        int cmd, k;
//        cin >> cmd >> k;
//        array <ll, 12> c;
//        for (int i = 0; i < k; ++i)
//            cin >> c[i];
//        for (int i = 0; i < k; ++i)
//            st.upd(st.p, c[i], c[i] * cmd);
//        cout << st.check() << "\n";
//    }
//}

//signed main() {
//    cin.tie(0) -> sync_with_stdio(0);
//    #ifdef JASPER2
//        freopen("in1", "r", stdin);
//    #endif
//
//    int Test = 1;
//    //cin >> Test;
//    for (int test = 1; test <= Test; test++){
//
//        run_case();
//    }
//}
