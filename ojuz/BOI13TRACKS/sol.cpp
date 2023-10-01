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
const int MAX = 4005;

int n, m;
char a[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int d[MAX][MAX];


bool isInside(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '.');
}

void run_case(){
	cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    int ans = 1;
    deque<pii> q;
    q.push_front({1, 1});
    d[1][1] = 1;
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop_front();
        ckmax(ans, d[x][y]);
        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isInside(nx, ny) && d[nx][ny] == 0){
                if (a[x][y] == a[nx][ny]){
                    d[nx][ny] = d[x][y];
                    q.push_front({nx, ny});
                }
                else {
                    d[nx][ny] = d[x][y] + 1;
                    q.push_back({nx, ny});
                }
            }
        }
    }
	cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter

