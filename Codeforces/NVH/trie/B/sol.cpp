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
        Node* child[26];
        // so xau s;
        int cnt;
        // so xau nhan s lam tien to;
        int prf;

        Node () {
            for (int i = 0; i < 26; ++i) child[i] = NULL;
            cnt = prf = 0;
        }
    };

    Node* root;
    Trie() {
        root = new Node();
    }

    void add(string s) {
        Node* p = root;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int nxt = s[i] - 'a';
            if (p->child[nxt] == NULL)
                p->child[nxt] = new Node();
            p = p->child[nxt];
            p->prf++;
        }
        p->cnt++;
    }

    int get(string s) {
        Node*p = root;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int nxt = s[i] - 'a';
            if (p->child[nxt] == NULL)
                return 0;
            p = p->child[nxt];
        }
        return p->prf;
    }
};

int n, q;
void run_case() {
    Trie trie;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        trie.add(s);
    }
    cin >> q;
    while (q--) {
        string s; cin >> s;
        cout << trie.get(s) << "\n";
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


