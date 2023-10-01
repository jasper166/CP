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

int n, q;
string a[MAX];
string ans;

struct Trie {
    int child[26], pos;
    int cnt = 0;
} tr[MAX];

int N = 0;
void add(string s, int id) {
    int p = 0;
    for (auto &c : s) {
        int nxt = c - 'a';
        if (tr[p].child[nxt] == 0)
            tr[p].child[nxt] = ++N;
        p = tr[p].child[nxt];
    }
    if (tr[p].pos == 0) tr[p].pos = id;
    else if (a[id] < a[tr[p].pos]) tr[p].pos = id;
}

void cal(string cur) {
    if (ans.empty() || (cur.size() > ans.size())) {
        ans = cur;
        return;
    }
    if (cur.size() == ans.size()) ans = min(ans, cur); 
}

int pr[MAX];
void dfs(string s, int root, int pos) {
    if (tr[root].pos) cal(a[tr[root].pos]);
    for (int i = pr[pos - 1] + 1; i < (int) s.size(); ++i) {
        int nxt = s[i] - 'a';
        if (tr[root].child[nxt]) {
            pr[pos] = i;
            dfs(s, tr[root].child[nxt], pos + 1);
        }
    }
}


void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        string y = a[i];
        sort(y.begin(), y.end());
        add(y, i);
    }
    cin >> q;
    pr[0] = -1;
    for (int i = 1; i <= q; ++i) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        // cout << s << "\n";aa
        ans.clear();
        dfs(s, 0, 1);
        if (ans.empty()) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << ans << "\n";
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


