#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 5;

const int BLOCK = 325;
int n, q;
int a[MAX];
vector <int> bl[BLOCK];

void upd(int x, int val) {
    int X = x / BLOCK;
    auto iter = lower_bound(bl[X].begin(), bl[X].end(), a[x]);
    if (iter != bl[X].end()) {
        int pos = (int) (iter - bl[X].begin());
        // debug(pos);
        a[x] = val;
        bl[X][pos] = val;
    }
    sort(bl[X].begin(), bl[X].end());
}

int qry(int l, int r, int k) {
    int L = l / BLOCK;
    int R = r / BLOCK;

    int cnt = 0;
    // if in the same block
    if (L == R) {
        for (int i = l; i <= r; i++)
            if (a[i] >= k)
                cnt++;
        return cnt;
    }

    for (int i = l; i <= min(r, (L + 1) * BLOCK - 1); i++)
        if (a[i] >= k)
            cnt++;
    for (int i = max(l, R * BLOCK); i <= r; i++) {
        if (a[i] >= k)
            cnt++;
    }
    for (int i = L + 1; i < R; i++) {
        int I = i;
        auto lo = lower_bound(bl[I].begin(), bl[I].end(), k);
        if (lo != bl[I].end()) {
            int rt = (int) (bl[I].end() - bl[I].begin());
            int lt = (int) (lo - bl[I].begin());
            cnt += (int) (rt - lt);
        }
    }
    return cnt;
}



void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        bl[i / BLOCK].push_back(a[i]);
    for (int i = 1; i <= n; i++) {
        int I = i / BLOCK;
        sort(bl[I].begin(), bl[I].end());
    }
    cin >> q;
    while (q--) {
        int cmd, x, y, z;
        cin >> cmd >> x >> y;
        if (cmd) {
            upd(x, y);
        }
        else {
            cin >> z;
            int ans = qry(x, y, z);
            cout << ans << "\n";
        }
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

