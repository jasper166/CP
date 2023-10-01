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
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9 + 1e2;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

struct DynamicSegmentTree {
    struct Node {
        int lx, rx;
        int ans, x, y, cnt;
        Node *l, *r;
        Node(int _lx, int _rx) {
            lx = _lx;
            rx = _rx;
            ans = INF;
            x = INF;
            y = -INF;
            cnt = 0;
            l = r = NULL;
        }
    };

    Node *p;
    void rmk(int l, int r) {
        p = new Node(l, r);
    }
 
    void upd(Node *root, int pos, int val) {
        if (pos < root->lx || pos > root->rx || root == NULL)
            return;

        if (root->x <= val)
        	root->ans = min(root->ans, val - root->x);
        if (root->y >= val)
        	root->ans = min(root->ans, root->y - val);
       	root->x = min(root->x, val);
        root->y = max(root->y, val);
        root->cnt++;

        if (root->lx != root->rx) {
            int m = (root->lx + root->rx) >> 1;
            if (root->l == NULL)
                root->l = new Node(root->lx, m);            
            if (root->r == NULL)
                root->r = new Node(m + 1, root->rx);
            upd(root->l, pos, val); 
            upd(root->r, pos, val);
		            
            root->x = min({root->x, root->l->x, root->r->x});
            root->y = max({root->y, root->l->y, root->r->y});
            root->cnt = root->l->cnt + root->r->cnt;
            root->ans= min({root->ans, root->r->x - root->l->y, root->l->ans, root->r->ans});
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
       	res.x = min({res.x, ql.x, qr.x});
       	res.y = max({res.y, ql.y, qr.y});
       	res.cnt = ql.cnt + qr.cnt;
       	res.ans = min({res.ans, ql.ans, qr.ans, qr.x - ql.y});
       	// debug(root->lx, root->rx, l, r, res.ans, res.x, res.y);
       	// debug(ql.ans, qr.ans, qr.x, ql.y);
        return res;
    }

    int qry(int l, int r) {
        Node z = qry(p, l, r);
        // debug(z.cnt);
        if (z.cnt <= 1) return -1;
        else return z.ans;
    }
    void upd(int pos, int val) {
    	upd(p, pos, val);
    }
};

int n, q;
void run_case() {
	cin >> n >> q;
	DynamicSegmentTree st;
	st.rmk(0, 1e9 + 5);
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		st.upd(x, x);
	}
	for (int i = 1; i <= q; ++i) {
		int cmd, x, y;
		cin >> cmd;
		if (cmd == 1) {
			cin >> x;
			st.upd(x, x);
		}
		else {
			cin >> x >> y;
			cout << st.qry(x, y) << "\n";
		}
	}
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}