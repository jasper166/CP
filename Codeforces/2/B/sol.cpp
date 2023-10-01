#include "bits/stdc++.h"
// @Jasper


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

int n;
int dp[MAX][MAX];
pii store[MAX][MAX], trace[MAX][MAX];
int a[MAX][MAX]; 

pii get_p(int x){
    int p2 = 0, p5 = 0;
    while (x % 2 == 0){
        p2++;
        x /= 2;
    }
    while (x % 5 == 0){
        p5++;
        x /= 5;
    }
    return make_pair(p2, p5);
}

int dx[] = {0, -1};
int dy[] = {-1, 0};
char dir[] = {'R', 'D'};
string path;

void trace_path(){
    pii st = {n, n};
    while (st != make_pair(-1, -1)){
        auto [curx, cury] = st;    
        for (int k = 0; k < 2; k++){
            int prex = curx + dx[k];
            int prey = cury + dy[k];
            if (make_pair(prex, prey) == trace[curx][cury]) path += (char) dir[k];
          //  debug(st);
          //  debug(prex, prey);
        }
        st = trace[st.fi][st.se];
    }
    reverse(all(path));
}

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    store[1][1] = get_p(a[1][1]);
    trace[1][1] = make_pair(-1, -1);
    dp[1][1] = min(store[1][1].fi, store[1][1].se);

    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == 1 && j == 1) continue;

            pii cur = get_p(a[i][j]);
           // debug(a[i][j]);
            // pii nxt;
            int cur_p = INF;
            pii pos = {-1, -1};
            for (int k = 0; k < 2; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (!(1 <= ni && ni <= n && 1 <= nj && nj <= n)) continue;
                pii pre = store[ni][nj];
            //    debug(i, j, ni, nj);
              //  debug(pre, cur);
                int nxt_p = min(pre.fi + cur.fi, pre.se + cur.se);
                if (nxt_p < cur_p){
                    cur_p = nxt_p;
                    pos = {ni, nj};
                }
            }

            dp[i][j] = cur_p;
            store[i][j] = make_pair(store[pos.fi][pos.se].fi + cur.fi, store[pos.fi][pos.se].se + cur.se);
            trace[i][j] = pos;
            // debug(dp[i][j]);
        }
    }
   // FOR(i, 1, n) FOR(j, 1, n) cout << trace[i][j].fi << " " << trace[i][j].se << "\n";

    cout << dp[n][n] << "\n";
    trace_path();
    cout << path << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


