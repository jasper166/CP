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

// #define int long long
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int B = 30;

struct Trie {
    int tr[N * 32][2];
    int cnt = 0;
    int root;
     
    int Node() {
        int x = ++cnt;
        tr[x][0] = tr[x][1] = 0;
        return x;
    }
    void add(int x) {
        int p = root;
        for (int i = 30; i >= 0; --i) {
            int d = (x >> i) & 1;
            if (!tr[p][d])
                tr[p][d] = Node();
            p = tr[p][d];
        }
    }
     
    int get(int x) {
        int ans = 0;
        int p = root;
        for (int i = 30; i >= 0; --i) {
            int d = (x >> i) & 1;
            if (tr[p][d ^ 1]) {
                ans |= (1 << i);
                p = tr[p][d ^ 1];
            }
            else 
                p = tr[p][d];
        }
        return ans;
    }
    void init() {
        cnt = 0, root = Node();
        add(0);
    }
} trie;

// DnC
int n, a[N];
int ans;

void dnc(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    int xorL, xorR, maxL, maxR, tl, tr;

    // Solving for left part
    tr = m + 1;
    trie.init();
    xorL = 0, xorR = 0, maxL = 0;
    for (int i = m; i >= l; --i) {
        maxL = max(maxL, a[i]);
        xorL ^= a[i];
        while (tr <= r && a[tr] <= maxL) {
            xorR ^= a[tr];
            trie.add(xorR);
            ++tr;
        }
        ans = max(ans, trie.get(maxL ^ xorL));
    }
    // Solving for right part
    tl = m;
    trie.init();
    xorL = 0, xorR = 0, maxR = 0;
    for (int i = m + 1; i <= r; ++i) {
        maxR = max(maxR, a[i]);
        xorR ^= a[i];
        while (tl >= l && a[tl] <= maxR) {
            xorL ^= a[tl];
            trie.add(xorL);
            --tl;
        }
        ans = max(ans, trie.get(maxR ^ xorR));
    }
    dnc(l, m);
    dnc(m + 1, r);
}

void run_case() {
	cin >> n;
    // cnt = 1;
	for (int i = 1; i <= n; ++i) cin >> a[i];
    ans = 0;
    dnc(1, n);
    cout << ans << "\n";
}
/*
    If we can fixed the maximum X, we can solve for any subarray having that maximum = X;
*/
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
