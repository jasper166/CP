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
        int cnt, prf;
        Node() {
            for (int i = 0; i < 26; ++i) child[i] = NULL;
            cnt = prf = 0;
        }
    };
    Node* root;
    Trie() {
        root = new Node();
    }

    void add(const string& s) {
        Node* p= root;
        for (auto& c : s) {
            int nxt = c - 'a';
            if (p->child[nxt] == NULL)
                p->child[nxt] = new Node();
            p = p->child[nxt];
            ++p->prf;
        }
        ++p->cnt;
    }

    bool find(const string& s) {
        if (s.empty()) return 0;
        Node*p = root;
        // debug(s);
        for (auto& c : s) {
            int nxt = c - 'a';
            if (p->child[nxt] == NULL)
                return 0;
            p = p->child[nxt];
        }
        return (p->cnt > 0);
    }

};

int n;
int f[MAX];
void run_case() {
    Trie tr;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        tr.add(s);
    }
    string x; cin >> x;
    int m = x.size();
    f[0] = 1;
    x = "$" + x;
    for (int i = 0; i < m; ++i) {
        string y;
        for (int j = i + 1; j <= min(100 + i, m); ++j) {
            y += x[j];
            if (tr.find(y))
                f[j] = (f[j] + f[i]) % MOD;
        }
    }
    cout << f[m] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


