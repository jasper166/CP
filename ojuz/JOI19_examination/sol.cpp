#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define fi first
#define se second
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long

using pii = pair < int, int >;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

struct Fenwick {
    int n;
    vector <int> f;
    void init (int _n) {
        n = _n;
        f.resize(_n + 5);
    }
    int get(int x) {
        int ans = 0;
        for (; x; x -= x & -x)
            ans += f[x];
        return ans;
    }
    void upd(int x, int val) {
        for (; x <= n; x += x & -x)
            f[x] += val;
    } 
    int qry(int l) { return get(n) - get(l - 1); }
} fen;


int n, q;
int a[N], ans[N];
vector <vector <int>> queries;

void dnc(int l, int r) {
    if (l == r) return;

    int m = (l + r) / 2;
    dnc(l, m);
    dnc(m + 1, r);

    vector <vector <int>> qs;
    // Al < Am < Ar -> only take student in right to update 
    for (int i = m + 1; i <= r; ++i) {
        auto x = queries[i];
        if (x[3] == -1)
            qs.push_back({x[1], x[2], -1});
    }

    // Solving queries in the left
    for (int i = l; i <= m; ++i) {
        auto x = queries[i];
        if (x[3] != -1)
            qs.push_back({x[1], x[2], x[3]});
    }
    sort(qs.begin(), qs.end());
    reverse(qs.begin(), qs.end());
    // Sort by Informatics points
    for (auto& x : qs) {
        if (x[2] == -1)
            fen.upd(x[1], 1);
        else 
            ans[x[2]] += fen.qry(x[1]);
    }

    // Undoing changes
    for (auto& x : qs) {
        if (x[2] == -1)
            fen.upd(x[1], -1);
    }
}

void run_case() {
    cin >> n >> q;

    vector <int> val;
    val.push_back(INF);
    val.push_back(-INF);
    int Q = n + q;
    for (int i = 1; i <= n; ++i) {
        int s, t; 
        cin >> s >> t;
        queries.push_back({s, t, s + t, -1});
        val.push_back(s);
        val.push_back(t);
        val.push_back(s + t);
    }

    for (int i = 1; i <= q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        queries.push_back({x, y, z, i});
        val.push_back(x);
        val.push_back(y);
        val.push_back(z);
    }

    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());

    int sz = val.size();
    fen.init(2 * sz + 5);
    // sort by Maths points
    sort(queries.begin(), queries.end());
    
    for (auto& x : queries) {
        for (int i = 0; i < (int) x.size() - 1; ++i)
            x[i] = lower_bound(val.begin(), val.end(), x[i]) - val.begin() + 1; 
    }

    dnc(0, Q - 1);
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


