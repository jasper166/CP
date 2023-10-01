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
#define TASK "OLP39"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

int q;

struct fenwick_2D{
    int f[MAX][MAX];
    fenwick_2D() = default;

    void update(int x, int y, int val){
        for (; x < MAX; x += (x & (-x))){
            int ny = y;
            for (; ny < MAX; ny += (ny & (-ny)))
                f[x][ny] += val;
        }
    }

    int get(int x, int y){
        int ans = 0, ny;
        for (; x; x -= (x & (-x))){
            ny = y;
            for (; ny; ny -= (ny & (-ny)))
                ans += f[x][ny];
        }
        return ans;
    }

    int get_rect(int x1, int y1, int x2, int y2){
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    }
};

fenwick_2D bit;

ll triangle(int a, int b, int c, int d){
    int p = bit.get_rect(a, b, c, d);
    return 1LL * p * (p - 1) * (p - 2) / 6;
}

void run_case(){
    cin >> q;
    
    for (int i = 1; i <= q; i++){
        int op, a, b, c, d, x, y;
        cin >> op;
        if (op == 1){
            cin >> x >> y;
            bit.update(x, y, 1);
        }
        else {
            cin >> a >> b >> c >> d;
            cout << triangle(a, b, c, d) << "\n";
        }
    }
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




