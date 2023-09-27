#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#ifdef LOCAL
#include "debug.h"
#define TASK "OLP40"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

#define int long long

struct query{
    int l, r, idx;
    bool operator < (query x) const {
        if (l != x.l) 
            return l < x.l;
        else if (l == x.l && r != x.r)
            return r < x.r;
        else
            return idx < x.idx;
    }
} q[MAX];
int n, m;
int a[MAX], ret[MAX];
int d[MAX];
vector <int> prime;

int pw(int a, int b){
    int ans = 1;
    while (b){
        if (b & 1) ans = (ans % MOD * a % MOD + MOD) % MOD;
        a = (a % MOD * a % MOD + MOD) % MOD;
        b >>= 1;
    }
    return ans;
}

int inv(int x){return pw(x, MOD - 2);}

void prepare(){
    for (int i = 2; i < MAX; i++) d[i] = (i & 1)? i : 2;    
    for (int i = 3; i <= sqrt(MAX); i++)
        if (d[i] == i)
            for (int j = i * i; j < MAX; j += i)
                d[j] = min(d[j], i);

    for (int i = 2; i < MAX; i++) 
        if (d[i] == i) 
            prime.push_back(i);

}


struct fenwick{
    int f[MAX];
    int n;
    fenwick(int N){
        n = N;
        for (int i = 1; i <= n; i++) f[i] = 1;
    }
    void update (int x, int val){
        for (; x <= n; x += (x & (-x))){
            f[x] = (1LL * f[x] % MOD * val % MOD + MOD) % MOD;
        }
    }
    int get(int x){
        int ans = 1;
        for (; x; x -= (x & (-x)))
            ans = (1LL * ans % MOD * f[x] % MOD + MOD) % MOD;
        return ans;
    }
    int get_range(int l, int r){
        return (1LL * get(r) * inv(get(l - 1)) + MOD) % MOD;
    }
};

vector <int> p[MAX];

void run_case(){
    prepare();

    cin >> n;
    fenwick bit(n);

    // cout << pw(2, 4) << "\n";

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        bit.update(i, a[i]);
    }
    for (int i = n; i >= 1; i--){
        int x = a[i];
        while (x != 1){
            p[d[x]].push_back(i);
            x /= d[x];
        }
    }
    // FOR(i, 1, n) cout << bit.f[i] << "\n";
    for (auto x : prime){
        // cout << x << "\n";
        if (!p[x].empty()){
            int val = (1LL * (x - 1) * inv(x) % MOD + MOD) % MOD;
            bit.update(p[x].back(), val);
        }
    }
    // FOR(i, 1, n) cout << bit.f[i] << "\n";
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
    }

    sort(q + 1, q + 1 + m);
    int j = 1;
    for (int i = 1; i<= m; i++){
        auto [l, r, idx] = q[i];
        for (; j < l; j++){
            int x = a[j];
            while (x != 1){
                p[d[x]].pop_back();
                if (!p[d[x]].empty()){
                    int val = (1LL * (d[x] - 1) * inv(d[x]) % MOD + MOD) % MOD; 
                    bit.update(p[d[x]].back(), val);
                }
                x /= d[x];
            }
        }
        ret[idx] = bit.get_range(l, r);
    }
    //FOR(i, 1, m) cout << q[i].l << " " << q[i].r << " " << q[i].idx << "\n";
    for (int i = 1; i <= m; i++)
        cout << ret[i] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}





