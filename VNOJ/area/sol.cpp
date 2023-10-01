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

struct Rect {
    int x, y1, y2, id;
    bool operator < (const Rect &o) const {
        return ((x < o.x) || (x == o.x && id < o.id));
    }
};

struct Node {
    int cnt, len;
    Node () {
        cnt = 0;
        len = 0;
    }
};

struct SegTree {
    Node f[MAX << 2];

    void upd(int x, int l, int r, int u, int v, int val) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            f[x].cnt += val;
            if (f[x].cnt)
                f[x].len = r - l + 1;
            else if (l != r)
                f[x].len = f[x << 1].len + f[x << 1 | 1].len;
            else
                f[x].len = 0;
                
            return;
        }
        int m = (l + r) >> 1;
        upd(x << 1, l, m, u, v, val);
        upd(x << 1 | 1, m + 1, r, u, v, val);
        if (f[x].cnt)
            f[x].len = r - l + 1;
        else    
            f[x].len = f[x << 1].len + f[x << 1 | 1].len;
    }

} st;


int n;
void run_case() {

    cin >> n;
    vector <Rect> events;
    events.push_back({0, 0, 0, -1});
    int yMAX = 0;

    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});   
        yMAX = max({yMAX, y1, y2});
    }
    sort(events.begin(), events.end());
    events[0].id = 0;
    ll ans = 0;
    for (auto [x, y1, y2, id] : events){
        debug(x, y1, y2, id);
    }

    for (int i = 1; i < (int) events.size(); i++) {
        auto [x, y1, y2, id] = events[i];
        ans += 1ll * st.f[1].len * (events[i].x - events[i - 1].x);
        st.upd(1, 0, yMAX, y1, y2 - 1, id);
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

