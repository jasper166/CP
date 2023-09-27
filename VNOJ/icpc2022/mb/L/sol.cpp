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
#define sz(x) (int) (x.size())
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve();

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
// }}}

void solve() {
    int nRow, nCol, s; cin >> nRow >> nCol >> s;
    vector<vector<int>> a(nRow, vector<int> (nCol, 0));

    auto get_ids = [&] (int n) {
        vector<int> res(n);
        std::iota(res.begin(), res.end(), 0);
        return res;
    };

    for (auto& row : a) {
        for (int& x : row) cin >> x;
    }

    vector<int> a_ids = get_ids(nRow);
    vector<int> b_ids = a_ids;
    for (int i = 0; i < s; ++i) {
        int k; cin >> k;
        --k;
        std::stable_sort(b_ids.begin(), b_ids.end(), [&] (int r1, int r2) {
                return a[r1][k] < a[r2][k];
                });
    }

    if (a_ids == b_ids) {
        cout << 0 << endl;
        return;
    }

    vector<int> res;
    vector<int> ids = get_ids(nCol);

    do {
        auto cur = get_ids(nRow);
        REP(i,nCol) {
            int x = ids[i];
            std::stable_sort(cur.begin(), cur.end(), [&] (int r1, int r2) {
                    return a[r1][x] < a[r2][x];
                    });

            if (cur == b_ids) {
                vector<int> t { ids.begin(), ids.begin() + i + 1 };
                if (res.empty() || sz(res) > i+1 || (sz(res) == i+1 && res > t)) {
                    res = t;
                }
                break;
            }
        }
    } while (next_permutation(ids.begin(), ids.end()));

    cout << sz(res) << '\n';
    for (int x : res) cout << 1+x << ' ';
    cout << endl;
}