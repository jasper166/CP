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
const int MAX = 1e6 + 5;

int kx, ky, px, py, turn;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};


void run_case(){
    cin >> kx >> ky >> px >> py >> turn;
    kx++; ky++; px++; py++;

    if (turn == 1) turn = 0, px++;
    if ((kx - px + ky - py) % 2 == 0){
        cout << "NO\n";
        exit(0);
    }
    
    queue <pii> q;
    q.emplace(kx, ky);
    map <pair<int, int>, bool> vis;
    vis[make_pair(kx, ky)] = 1;
    int ans = 0;
    for (; ;){
        if (turn){
            px++;
            for (int k = 0; k < 8; k++){
                int nx = px + dx[k];
                int ny = py + dy[k];
                if (vis[make_pair(nx, ny)]){
                    cout << "YES\n" << ans << "\n";
                    exit(0);
                }
            }
        }
        else {
            ans++;
            while (!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 8; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (vis[make_pair(nx, ny)] == 0){
                        vis[make_pair(nx, ny)] = 1;
                        q.emplace(nx, ny);         
                    }
                }
            }
        }
    
        turn ^= 1;
        //px++; 
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

