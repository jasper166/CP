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
const int MAX = 1e5 + 5;

struct Point {
    int x, y, id;
    bool operator < (const Point &o) const {
        return ((x == o.x && y < o.y) || (x < o.x));
    }
} a[MAX];


struct cmpY{
    bool operator () (const Point &A, const Point &B) const {
        return ((A.y == B.y && A.x < B.x) || (A.y < B.y));
    }  
};

ll dist(Point A, Point B) {
    return 1ll * (A.x - B.x) * (A.x - B.x) + 1ll * (A.y - B.y) * (A.y - B.y);
}

int n;
void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    
    sort(a + 1, a + 1 + n);
    ll d = dist(a[1], a[2]);
    pii res = {1, 2};
    int LIM = 1e6;
    set <Point, cmpY> st;  
    
    for (int i = 1; i <= n; i++) {
        // find in range [y - d, y + d];
        auto [x, y, id] = a[i];
        Point cur = {-LIM, y - (int) sqrt(d), -1};
        for (;;) {
            // debug(i);
            auto iter = st.upper_bound(cur);
            if (iter == st.end() || (iter->y > y + d))
                break;

            cur = *iter;
            if (cur.x < x - d) {
                st.erase(iter);
                continue;
            }

            if (dist(a[i], cur) < d) {
                d = dist(a[i], cur);
                res = make_pair(id, cur.id);
            }
        }   
        st.insert(a[i]);
    }
    --res.fi, --res.se;
    if (res.fi > res.se) swap(res.fi, res.se);
    // cout << res.fi << " " << res.se << " ";
    cout << fixed << setprecision(6) << sqrt(d) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

