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
const int MAX = 3e5 + 5;

int n;
struct Data {
    int a, h, id;
    bool operator < (const Data& x) const{
        return (a < x.a) || (a == x.a && h < x.h);
    }

} ar[MAX];

struct fenwick {
    int f[MAX];
    int n;
    
    fenwick (int n){
        this->n = n;
        memset (f, 0, sizeof f);
    }
    int get(int x){
        int res = 0;
        for (; x; x -= x & -x)
            res += f[x];
        return res;
    }

    void update(int x, int val){
        for (; x < MAX; x += x & -x)
            f[x] += val;
    }
};

int res[MAX];
void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> ar[i].a >> ar[i].h;
        ar[i].id = i;
    }
    sort(ar + 1, ar + 1 + n);
    fenwick f(n);

    for (int i = 1; i <= n; i++){
        cout << ar[i].a << " " << ar[i].h << " " << ar[i].id <<  "\n";
    }

    for (int i = 1; i <= n; i++){
        int pos = i;
        while (i < n && ar[pos].a == ar[i + 1].a && ar[pos].h == ar[i + 1].h) i++;
        int cur = f.get(ar[pos].h);
        //debug(pos, i);
        for (int k = pos; k <= i; k++)
            res[ar[k].id] = cur;
       // debug(cur, i - pos + 1);
        f.update(ar[i].h, i - pos + 1);
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << "\n";

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

