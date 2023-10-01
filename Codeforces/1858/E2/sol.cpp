#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Fenwick {
    int n;
    vector <int> f;
    Fenwick(int _n) : n(_n), f(_n + 5) {};
    void add(int x, int val) {
        for (; x <= n; x += x & -x)
            f[x] += val;
    }
    int qry(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x)
            ans += f[x];
        return ans;
    }
};


int pos[N];
int n = 1, q;
int a[N];
void run_case() {

    Fenwick bit(N);
    fill(pos, pos + N, N);
    cin >> q;
    vector <array<int, 5>> roll;
    for (int _ = 1; _ <= q; _++) {
        char cmd; cin >> cmd;
        // debug(pos[1], pos[2]);
        if (cmd == '+') {
            int x; cin >> x;
            roll.push_back({-1, x, pos[x], a[n], pos[a[n]]});
            if (pos[a[n]] == n) {
                bit.add(pos[a[n]], -1);
                pos[a[n]] = N;
                bit.add(pos[a[n]], 1);
            }
            if (pos[x] > n) {
                // first time appearing
                bit.add(pos[x], -1);
                pos[x] = n;
                bit.add(pos[x], 1);
            }
            a[n] = x;
            ++n;
        }
        else if (cmd == '-') {
            int k; cin >> k;
            n -= k;
            roll.push_back({k, 0});
        }
        else if (cmd == '?') {
            // debug(_, n);
            int ans = bit.qry(n - 1);
            cout << ans << endl;
        }
        else {
            auto &lst = roll.back(); roll.pop_back();
            
            n += lst[0];
            if (lst[0] == -1) {
                a[n] = lst[3];
                if (pos[lst[1]] != lst[2]) {
                    bit.add(pos[lst[1]], -1);
                    pos[lst[1]] = lst[2];
                    bit.add(pos[lst[1]], 1);
                }
                if (pos[lst[3]] != lst[4]) {
                    bit.add(pos[lst[3]], -1);
                    pos[lst[3]] = lst[4];
                    bit.add(pos[lst[3]], 1);
                }
            }
        }
    }
    // debug(bit.qry(-1));
    // debug(bit.qry(1), bit.qry(2), bit.qry(3));

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}



                                                    
