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
int a[MAX][MAX];
int p2[MAX][MAX], p5[MAX][MAX], f2[MAX][MAX], f5[MAX][MAX];
// special case: 0 appears in the matrix -> 1 if no other paths ending with no numbers of zeros found or 0 if found;
string path;
pii trace2[MAX][MAX], trace5[MAX][MAX];
int dx[] = {-1, 0};
int dy[] = {0, -1};
char dir[] = {'D', 'R'};


void trace(int op){
    pii st = {n, n};
    while (st != make_pair(1, 1)){
        pii to_trace = (op == 2)? trace2[st.fi][st.se] : trace5[st.fi][st.se];
        for (int i = 0; i < 2; i++){
            int ni = st.fi + dx[i];
            int nj = st.se + dy[i];
            if (make_pair(ni, nj) == to_trace) 
                path += dir[i];
        }
        st = to_trace;
    }
    reverse(all(path));
}



void run_case(){
    cin >> n;
    pii pos = {-1, -1};
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] == 0){
                pos = make_pair(i, j);
                p2[i][j] = p2[i][j] = 1;
                continue;
            }
            while (a[i][j] % 2 == 0){
                a[i][j] /= 2;
                p2[i][j]++;
            }
            while (a[i][j] % 5 == 0){
                a[i][j] /= 5;
                p5[i][j]++;
            }
        }
    }

    f2[1][1] = p2[1][1];
    f5[1][1] = p5[1][1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == 1 && j == 1) continue;
            int min2 = INF;
            int min5 = INF;
            pii prev2, prev5;
            for (int k = 0; k < 2; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (!(1 <= ni && ni && ni <= n && 1 <= nj && nj <= n)) continue;
                if (f2[ni][nj] < min2){
                    min2 = f2[ni][nj];
                    prev2 = {ni, nj};
                }
                if (f5[ni][nj] < min5){
                    min5 = f5[ni][nj];
                    prev5 = {ni, nj};
                }
            }
            f2[i][j] = p2[i][j] + min2;
            trace2[i][j] = prev2;
            f5[i][j] = p5[i][j] + min5;
            trace5[i][j] = prev5;
        }
    }
    // Special case
    if (min(f2[n][n], f5[n][n]) && pos != make_pair(-1, -1)){
        for (int i = 1; i < pos.fi; i++) path += 'D';
        for (int i = 1; i < pos.se; i++) path += 'R';
        for (int i = pos.fi; i < n; i++) path += 'D';
        for (int i = pos.se; i < n; i++) path += 'R';
        cout << "1\n" << path << "\n";
        exit(0);
    }
    int ans = min(f2[n][n], f5[n][n]);
    if (f2[n][n] < f5[n][n]) 
        trace(2);
    else 
        trace(5);
    cout << ans << "\n" << path << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


