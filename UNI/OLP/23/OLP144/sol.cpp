#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

struct DynamicSegmentTree {
    struct Node {
        int lx, rx;
        ll ans, cnt, sum;
        Node *l, *r;
        Node(int _lx, int _rx) {
            lx = _lx;
            rx = _rx;
            ans = cnt = sum = 0;
            l = r = NULL;
        }
    };

    Node *p;
    void rmk(int l, int r) {
        p = new Node(l, r);
    }
 
    void upd(Node *root, ll pos, ll val, ll type) {
        if (pos < root->lx || pos > root->rx || root == NULL)
            return;
        root->cnt += type;
        root->sum += val * type;
        if (root->lx != root->rx) {
            int m = (root->lx + root->rx) >> 1;
            if (root->l == NULL)
                    root->l = new Node(root->lx, m);            
            if (root->r == NULL)
                    root->r = new Node(m + 1, root->rx);
            upd(root->l, pos, val, type); 
            upd(root->r, pos, val, type);
            root->cnt = root->l->cnt + root->r->cnt;
            root->sum = root->l->sum + root->r->sum;
            root->ans = root->l->ans + root->r->ans 
                        + (root->r->sum * root->l->cnt - root->l->sum * root->r->cnt);
        }
    }
 
    Node qry(Node *root, int l, int r) {
        if (root->lx > r || root->rx < l || root == NULL)
            return Node(0, 0);
        if (l <= root->lx && root->rx <= r)
            return *root;
        Node ql = Node(0, 0), qr = Node(0, 0);
        if (root->l != NULL)
            ql = qry(root->l, l, r);
        if (root->r != NULL)
            qr = qry(root->r, l, r);
        Node res = Node(0, 0);
        res.cnt = ql.cnt + qr.cnt;
        res.sum = ql.sum + qr.sum;
        res.ans = ql.ans + qr.ans 
                        + (qr.sum * ql.cnt - ql.sum * qr.cnt);
        return res;
    }

    ll qry(int x, int y) {
        return qry(p, x, y).ans;
    }
};

int n, q;
int a[N];
void run_case() {
    cin >> n >> q;
    DynamicSegmentTree st;
    st.rmk(-1e9 - 5, 1e9 + 5);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        a[i] = x;
        st.upd(st.p, x, x, 1);
    }

    while (q--) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 1) {
            st.upd(st.p, a[x], a[x], -1);
            a[x] += y;
            st.upd(st.p, a[x], a[x], 1);
        }
        else {
            ll ans = st.qry(x, y);
            cout << ans << "\n";
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


