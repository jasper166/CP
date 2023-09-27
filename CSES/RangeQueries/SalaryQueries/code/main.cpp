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

struct BIT {
    vector <int> f;
    int N;
    BIT(int _N) : N(_N), f(_N + 5) {};

    void upd(int x, int val) {
        for ( ; x <= N; x += x & -x) f[x] += val;
    }

    int qry(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x)
            ans += f[x];
        return ans;
    }

    int qry(int l, int r) {
        if (l > r) swap(l, r);
        return qry(r) - qry(l - 1);
    }
};

int n, q;
int a[MAX];
vector <int> b;

int compress(int x) {
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}

void run_case() {
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    vector <array<int, 3>> queries;
    for (int i = 1; i <= q; ++i) {
        char cmd;
        int x, y;
        cin >> cmd >> x >> y;
        queries.push_back({cmd == '?', x, y});
        b.push_back(x);
        b.push_back(y);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());

    BIT bit(b.size() + 5);
    for (int i = 1; i <= n; ++i) {
        a[i] = compress(a[i]);
        bit.upd(a[i], 1);
    }
    for (auto _q : queries) {
        if (_q[0]) {
            int l = compress(_q[1]);
            int r = compress(_q[2]);
            cout << bit.qry(l, r) << "\n";
        }
        else {
            int x = compress(_q[2]);
            bit.upd(a[_q[1]], -1);
            a[_q[1]] = x;
            bit.upd(a[_q[1]], 1);
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
