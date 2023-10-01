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

int n, m;
char a[MAX][MAX];
int d[4][MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isOk(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '#');
}


void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m){
        cin >> a[i][j];
        REP(k, 4) d[k][i][j] = INF;
    }
    
    FOR(k, 1, 3){
        deque <pii> q;
        FOR(i, 1, n) FOR(j, 1, m){
            if (a[i][j] - '0' == k){
                d[k][i][j] = 0;
                q.push_front({i, j});
            }
        }
            
        while (!q.empty()){
            auto [x, y] = q.front();
            q.pop_front();
            REP(i, 4){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isOk(nx, ny)){
                    int w = (a[nx][ny] == '.');
                    if (d[k][x][y] + w < d[k][nx][ny]){
                        d[k][nx][ny] = d[k][x][y] + w;
                        if (w == 1) 
                            q.push_back({nx, ny});
                        else 
                            q.push_front({nx, ny});
                    }
                }
            }
        }
    }
    int ans = INF;
    FOR(i, 1, n) FOR(j, 1, m){
        if (d[1][i][j] != INF && d[2][i][j] != INF && d[3][i][j] != INF){ 
            int cur = d[1][i][j] + d[2][i][j] + d[3][i][j] - 2 * (a[i][j] == '.');
            if (cur == 3) cout << "i j: " << i << " " << j << "\n";
            ckmin(ans, cur);
        }
    }

    FOR(k, 1, 3){
        FOR(i, 1, n) FOR(j, 1, m) cout << d[k][i][j] << " \n"[j == m];
        cout << "\n\n";
    }
   
    if (ans >= INF) ans = -1;
    cout << ans << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



