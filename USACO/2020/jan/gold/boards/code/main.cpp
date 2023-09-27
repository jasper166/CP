#include "bits/stdc++.h"
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
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

struct SegmentTree {
    vector <int> f;
    int n;
    SegmentTree (int N) {
        n = N;
        f.assign(N << 1, INF);
    }

    int merge(int x, int y) {
        return min(x, y);
    }
    void upd(int p, int val) {
        p += n;
        f[p] = min(f[p], val);
        for (; p; p >>= 1)
            f[p >> 1] = merge(f[p], f[p ^ 1]);
    }

    int qry(int l, int r) {
        int ans = INF;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ans = min(ans, f[l++]);
            if (r & 1)
                ans = min(f[--r], ans);
        }
        return ans;
    }
};

int n, p;
int ans[MAX];
vector <int> y_axis;

int getCor(int x) {
    return lower_bound(y_axis.begin(), y_axis.end(), x) - y_axis.begin();
}

void run_case() {
    cin >> n >> p;

    vector <array<int, 4>> springs;
    for (int i = 0; i < p; ++i) {
        int x, y, X, Y;
        cin >> x >> y >> X >> Y;
        springs.push_back({x, y, i, 1});
        springs.push_back({X, Y, i, -1});
        y_axis.push_back(y);
        y_axis.push_back(Y);
    }

    sort(y_axis.begin(), y_axis.end());
    sort(springs.begin(), springs.end());
    SegmentTree st(p * 2);
    st.upd(0, 0);

    for (auto &[x, y, id, t] : springs) {
        if (t == 1)
            ans[id] = x + y + st.qry(0, getCor(y));
        else
            st.upd(getCor(y), ans[id] - x - y);
    }

//    debug(y_axis);
    int res = st.qry(0, 2 * p - 1) + 2 * n;
    cout << res << "\n";
}

void setUSACO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
// setUSACO("boards");

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
