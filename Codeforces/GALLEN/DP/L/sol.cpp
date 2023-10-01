// @Jasper
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

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
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

struct group{
    int c, p, id;
};
struct table{
    int id, c;
};
table r[MAX];
group a[MAX];
bool operator < (const group x, const group y){
    return x.c < y.c;
}
bool operator < (const table x, const table y){
    return x.c < y.c;
}
int n, k;
pii trace[MAX][MAX];
int f[MAX][MAX];
vector <pii> ans;

void retrace (int i, int j){
    if (i == 0 || j == 0) return;
    if (trace[i][j].fi == i - 1 && trace[i][j].se == j - 1){
        ans.push_back(make_pair(a[i].id, r[j].id));
    }
    retrace(trace[i][j].fi, trace[i][j].se);
}

void run_case(){
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i].c >> a[i].p;
        a[i].id = i;
    }
    cin >> k;
    FOR(i, 1, k){
        cin >> r[i].c;
        r[i].id = i;
    }
    sort (a + 1, a + 1 + n);
    sort (r + 1, r + 1 + k);
    memset(trace, -1, sizeof(trace));
    FOR(i, 1, n) FOR(j, 1, k){
        if (a[i].c <= r[j].c){
            f[i][j] = f[i - 1][j - 1] + a[i].p;
            trace[i][j] = make_pair(i - 1, j - 1);
        }
        if (f[i][j] < f[i - 1][j]){
            f[i][j] = f[i - 1][j];
            trace[i][j] = make_pair(i - 1, j);
        }
        if (f[i][j] < f[i][j - 1]){
            f[i][j] = f[i][j - 1];
            trace[i][j] = make_pair(i, j - 1);
        }
    }
    retrace(n, k);
    cout << ans.size() << " " << f[n][k] << "\n";
    for (auto [x, y] : ans){
        cout << x << " " << y << "\n";
    }
    cout << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}



