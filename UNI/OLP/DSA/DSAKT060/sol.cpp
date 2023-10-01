#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;
using ull = unsigned long long;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

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
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

struct FenwickTree {
    ull *f;
    int n;
    FenwickTree (int N) {
        this->n = N;
        f = new ull[N + 1];
        for (int i = 0; i <= N; i++)
            f[i] = 0;
    }

    ull get (int x) {
        ull res = 0;
        for (; x; x -= x & -x)
            res += f[x];
        return res;
    }

    void update (int x, ull val) {
        for (; x <= n; x += x & -x)
            f[x] += val;
    }

    ull query (int l, int r) {
        return get(r) - get(l - 1);
    }
};


int q;
string s;
ull p[MAX];
const ull BASE = 31;

void run_case(){
    cin >> s >> q;

    int n = s.size();
    s = "$" + s;
    FenwickTree pref(n), suff(n);

    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] * BASE;

    for (int i = 1; i <= n; i++) {
        ull val = (s[i] - '0') + 1;
        pref.update(i, val * p[i]);
        suff.update(i, val * p[n - i + 1]);
    }

    for (int Q = 1; Q <= q; Q++) {
        char x;
        cin >> x;
        if (x == 'q') {
            //query
            int l, r;
            cin >> l >> r;
            ull P = pref.query(l, r);
            ull S = suff.query(l, r);
            if (r + l >= n + 1) 
                S *= p[r + l - n - 1];
            else 
                P *= p[n + 1 - r - l];
            cout << ((S == P)? "YES\n" : "NO\n");
        }
        else {
            // update
            int i;
            char c;
            cin >> i >> c;
            ull val = c - s[i];
            pref.update(i, val * p[i]);
            suff.update(i, val * p[n - i + 1]);
            s[i] = c;
        }
    }

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

