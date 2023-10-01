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

const int BLOCK = 325;
const int MAX_VAL = 1e5;
// Mo's algo
struct Query {
    int l, r, id;
    bool operator < (const Query &o) const{
        if (l / BLOCK == o.l / BLOCK) 
            return (l / BLOCK & 1)? r > o.r : r < o.r;
        else
            return (l / BLOCK < o.l / BLOCK);
    }
} que[MAX];

int a[MAX];
int n, q, answer;
int ans[MAX];
int cnt[MAX];

void add(int x) {
    if (x > MAX_VAL) return;
    if (cnt[x] == x) answer--;
    cnt[x]++;
    if (cnt[x] == x) answer++;
}

void del(int x) {
    if (x > MAX_VAL) return;
    if (cnt[x] == x) answer--;
    cnt[x]--;
    if (cnt[x] == x) answer++;
}

void run_case() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> que[i].l >> que[i].r;
        que[i].id = i;
    }

    sort(que + 1, que + 1 + q);
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++) {
        while (l > que[i].l) add(a[--l]);
        while (r < que[i].r) add(a[++r]);
        while (l < que[i].l) del(a[l++]);
        while (r > que[i].r) del(a[r--]);
        ans[que[i].id] = answer; 
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

