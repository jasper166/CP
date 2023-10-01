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
const int MAX = 1e6 + 5;

struct Trie {
    struct Node {
        Node *child[2];
        int cnt;
        Node() {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };
    Node *root;
    Trie() {
        root = new Node();
    }
    void add(const int& x) {
        Node *p = root;
        for (int i = 29; i >= 0; --i) {
            int nxt = (x >> i) & 1;
            if (p->child[nxt] == NULL)
                p->child[nxt] = new Node();
            p = p->child[nxt];
        }
        ++p->cnt;
    }

    int find(const int &x) {
        Node *p = root;
        int res = 0;
        for (int i = 29; i >= 0; --i) {
            int nxt = (x >> i) & 1;
            if (p->child[nxt ^ 1] != NULL) {
                p = p->child[nxt ^ 1]; 
                res += (1 << i);
            }
            else {
                if (p->child[nxt] == NULL)
                    return res;
                p = p->child[nxt];
            }
        }
        return res;
    }
};

int n, a[MAX];
void run_case() {
    cin >> n;
    Trie tr;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans = max(ans, tr.find(a[i]));
        tr.add(a[i]);
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


