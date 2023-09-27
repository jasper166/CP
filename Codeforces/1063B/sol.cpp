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
const int MAX = 2005;

int n, m;
pii s, LR;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

char a[MAX][MAX];
int d[MAX][MAX];

bool isOk(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '*');
}

void run_case(){
    cin >> n >> m;
    cin >> s.fi >> s.se;
    cin >> LR.fi >> LR.se;
    
    FOR(i, 1, n) FOR(j, 1, m){
        cin >> a[i][j];
        d[i][j] = INF;
//       <F4>i d[i][j] = (a[i][j] == '.')? 0 : 2;
    }
    deque <pii> q;
    q.push_front(s);
    d[s.fi][s.se] = 0;

    while (!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        q.pop_front();
        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isOk(nx, ny)){
                int w = (i == 0);
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
    ll res = 0;
    FOR(i, 1, n) FOR(j, 1, m){
        if (d[i][j] == INF) continue;
        else {
            int L = d[i][j];
            int R = j - s.se + L;
            if (L <= LR.fi && R <= LR.se) res++;
        }
    }
        // FOR(i, 1, n) FOR(j, 1, m)
     //   cout << d[i][j] << " \n"[j == m];
    cout << res << "\n";
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



