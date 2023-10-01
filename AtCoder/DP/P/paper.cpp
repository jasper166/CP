#include "bits/stdc++.h"
//@etohari
using namespace std;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define WIFE "Dao Bich Ngoc"
#define el "\n"
#define fi first        
#define se second
#define bit(mask,i) ((mask >> i)&1)
#define cntbit(mask) __builtin_popcountll(mask)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define sz(s) (int)s.size()
#define __lcm(a,b) (1ll * a / __gcd(1ll * a, 1ll * b) * b)
#define rand(l, r) uniform_int_distribution < int64_t > (l, r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int DX[] = { };
const int DY[] = { };

int n, k, x[MAXN], y[MAXN], tree[MAXN];

void update(int p, int val) {
        for (;p < MAXN; p += (-p) & p) {
                tree[p] += val;
        }
}

int get(int p) {
        int ans = 0;
        for (;p > 0; p -= (-p) & p) {
                ans += tree[p];
        }
        return ans;
}

void etohari() {
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
                cin >> x[i] >> y[i];
        }

        priority_queue < pair < int, int > > qe;

        for (int i = 1; i <= n; i++) {
                qe.emplace(-y[i], x[i]);
                update(x[i], 1);
        }

        int64_t ans = 0;

        for (int min_y = 1; min_y < MAXN - 1; min_y++) {
                while (!qe.empty() && -qe.top().fi < min_y) {
                        update(qe.top().se, -1);
                        qe.pop();
                }

                int ans_l = -1;
                int ans_r = -1;

                for (int l = 0, r = MAXN - 1; l <= r; ) {
                        int m = l + r >> 1;
                        if (get(MAXN - 1) - get(m) <= k) {
                                ans_l = m;
                                r = m - 1;
                        }
                        else {
                                l = m + 1;
                        }
                }

                if (ans_l == -1 || (get(MAXN - 1) - get(ans_l) != k))continue;

                for (int l = 0, r = MAXN - 1; l <= r; ) {
                        int m = l + r >> 1;
                        if (get(MAXN - 1) - get(m) <= k - 1) {
                                ans_r = m;
                                r = m - 1;
                        }
                        else {
                                l = m + 1;
                        }
                }
                ans += ans_r - ans_l;
        }

        cout << ans;
}

signed main() {
        cin.tie(NULL)->sync_with_stdio(false);

        int test = 1;
        // cin >> test;

        for (int i_test = 1; i_test <= test; i_test++) {
                etohari();
        }

        return (0 ^ 0);
}
/*
        Hi I'm Powder
        fb.com/hai290605
        ICPC WORLD FINALS GO GO
*/
