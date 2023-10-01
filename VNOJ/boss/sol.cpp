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
const int MAX = 3e4 + 5;

struct Employee {
    int h, s, id;

    bool operator < (const Employee& o) const{
        if (h == o.h)
            return s < o.s;
        return h < o.h;
    }
} a[MAX];

struct FenwickTree {
    pii f[MAX];
    int n;
    void init(int N) {
        n = N;
        for (int i = 1; i < MAX; i++) f[i] = {INF, INF};
    }

    pii get(int x) {
        pii ans = {INF, INF};
        for (; x <= n; x += x & -x)
            ans = min(ans, f[x]);
        return ans; 
    }

    void modify(int w, int i) {
        for (int x = w; x; x -= x & -x)
            f[x] = min(f[x], {w, i});
    }
} bit;


int n, q;

void run_case() {
    cin >> n >> q;
    vector <int> salaries;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].id >> a[i].s >> a[i].h;
        salaries.push_back(a[i].s);
    }
    sort(all(salaries));
    sort(a + 1, a + 1 + n);
    bit.init(n);
    map <int, int> boss, minion;
    for (int i = n; i >= 1; --i) {
        int upper = (int) (lower_bound(all(salaries), a[i].s) - salaries.begin()) + 1;
        pii b = bit.get(upper + 1);
        boss[a[i].id] = (b.se == INF)? 0 : b.se;
        bit.modify(upper, a[i].id);
    }

    for (int i = 1; i <= n; i++) {
        int b = boss[a[i].id];
        int cnt = minion[a[i].id];
        minion[b] += cnt + 1;
    }
     for (int i = 1; i <= q; i++) {
        int x; cin >> x;
        cout << boss[x] << " " << minion[x] << "\n";
     }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

