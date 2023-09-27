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
const int MAX = 1e3 + 48;

struct Fenwick2D {
    int **f;
    int n, m;

    void init (int N, int M) {
        this->n = N;
        this->m = M;
        f = new int * [N + 1];    
        for (int i = 0; i <= N; i++){
            f[i] = new int[M + 1];
            fill(f[i], f[i] + 1 + M, 0);
        }
    }

    void update (int x, int y, int val){
        for (int X = x ; X <= n; X += X & -X)
            for (int Y = y; Y <= m; Y += Y & -Y)
                f[X][Y] += val;
    }
    
    int get (int x, int y){
        int res = 0;
        for (int X = x; X; X -= X & -X)
            for (int Y = y; Y; Y -= Y & -Y)
                res += f[X][Y];
        return res;
    }
    int get (int x, int y, int X, int Y){
        return get(X, Y) + get(x - 1, y - 1) - get(x - 1, Y) - get(X, y - 1);
    }
};

int op;

void run_case(){
    Fenwick2D f;
    while (cin >> op){
        debug(op);
        if (op == 0){
            int n; cin >> n;
            f.init(n, n);    
            debug(f.n, f.m);
        }
        else if (op == 1){
            int x, y, val;
            cin >> x >> y >> val;
            ++x, ++y;
            debug(x, y);
            f.update(x, y, val);
        }
        else if (op == 2){
            int x, y, X, Y;
            cin >> x >> y >> X >> Y;
            ++x, ++y, ++X, ++Y;
            debug(x, y, X, Y);
            debug(f.get(x, y), f.get(X, Y));
            cout << f.get(x, y, X, Y) << "\n";
        }
        else exit(0);
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

