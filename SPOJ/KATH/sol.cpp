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

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int d[MAX][MAX];
char a[MAX][MAX];
int n, m;

bool isInside(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) d[i][j] = INF, cin >> a[i][j];
    deque <pii> q;
    q.push_front({1, 1});
    d[1][1] = 0;
    while (!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        q.pop_front();
        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isInside(nx, ny)){
                int w = (a[nx][ny] != a[x][y]);
                if (d[x][y] + w < d[nx][ny]){
                    d[nx][ny] = d[x][y] + w;
                    if (w == 1)
                        q.push_back({nx, ny});
                    else 
                        q.push_front({nx, ny});
                }
            }
        }
    }

    cout << d[n][m] << "\n";

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



