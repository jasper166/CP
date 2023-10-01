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
bool a[MAX][MAX];
int d[MAX][MAX];
int dx[] = {-1, 0, 0, 1, -1, 1, 1, -1};
int dy[] = {0, 1, -1, 0, -1, -1, 1, 1};

bool isOk(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && d[x][y] == -1  && a[x][y]);
}


void run_case(){
	pii s, e;
    cin >> n >> m >> s.fi >> s.se >> e.fi >> e.se;
    s.fi++, s.se++, e.fi++, e.se++;
    FOR(i, 1, n) FOR(j, 1, m){
        int dummy; cin >> dummy;
        a[i][j] = (dummy == 1);
        d[i][j] = -1;
    }
  //  FOR(i, 1, n) FOR(j, 1, m) cout << a[i][j] << " \n"[j == m];
    if (a[s.fi][s.se] == 0 || a[e.fi][e.se] == 0){
        cout << "-1\n";
        return;
    }
    queue <pii> q;
    q.push({s.fi, s.se});
    d[s.fi][s.se] = 0;
    while (!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        if (x == e.fi && y == e.se) break;
        q.pop();
        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isOk(nx, ny)){
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    cout << d[e.fi][e.se] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter
