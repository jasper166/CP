#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e9 + 5;

struct Node {
    Node *left, *right;
    int cnt;
    Node() {
        left = right = NULL;
        cnt = 0;
    }
};

struct SegTree {
    Node *root = new Node();
    SegTree() {
        root = new Node();
    }
    void upd(Node *p, int l, int r, int x) {
        if (x < l || x > r)
            return;
        if (l == r) {
            p->cnt++;
            return;
        }
        int m = (l + r) / 2;
        if (p->left == NULL)
            p->left = new Node();
        if (p->right == NULL)
            p->right = new Node();
        upd(p->left, l, m, x);
        upd(p->right, m + 1, r, x);
        p->cnt = p->left->cnt + p->right->cnt;
    }
    int qry(Node* p, int l, int r, int k) {
        if (l == r)
            return l;
        int m = (l + r) / 2;
        int qL = (p->left == NULL)? 0 : p->left->cnt;
        int qR = (p->right == NULL)? 0 : p->right->cnt;
        if (qL >= k)
            return qry(p->left, l, m, k);
        else
            return qry(p->right, m + 1, r, k - qL);
    }
};


int n;
void run_case() {
    SegTree st;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int cmd, x; cin >> cmd >> x;
        if (cmd == 1)
            st.upd(st.root, 1, MAX, x);
        else
            cout << st.qry(st.root, 1, MAX, x) << "\n";
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


