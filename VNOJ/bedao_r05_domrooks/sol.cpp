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

#define int long long

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int cnt, n;
vector <int> adj[MAX];
int usedR[MAX], usedC[MAX];
int vis[MAX];

int mPow(int a, int x){
    int ans = 1;
    while (x){
        if (x & 1) ans = (ans * a + MOD) % MOD;
        a = (a * a + MOD) % MOD;
        x >>= 1;
    }
    return ans;
}

void dfs(int u, int p){
    vis[u] = 1;
    for (int v : adj[u]){
        if (v == p) 
            continue;
        if (vis[v] == 1){
            ++cnt;
            break;
        }
        else if (!vis[v])
            dfs(v, u);
    }
    vis[u] = 2;
}



void run_case(){
    cin >> n;

    for (int curRook = 1; curRook <= n; curRook++){
        int r, c;
        cin >> r >> c;
        // considering current row
        if (!usedR[r])
            usedR[r] = curRook;
        else {
            int preRook = usedR[r];
            adj[preRook].push_back(curRook);
            adj[curRook].push_back(preRook);
        }
        //considering current column
        if (!usedC[c])
            usedC[c] = curRook;
        else {
            int preRook = usedC[c];
            adj[preRook].push_back(curRook);
            adj[curRook].push_back(preRook);
        }
        
    }
    
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, 0);
    
    debug(cnt); 
    cout << mPow(2, cnt) << "\n";
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

