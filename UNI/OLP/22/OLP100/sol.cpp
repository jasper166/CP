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
#define TASK "olp100"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif
// FAST IO
namespace IO {
    const int BUFFER_SIZE = 1 << 15;
 
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
 
    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
 
        if (input_len == 0)
            input_buffer[0] = EOF;
    }
 
    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();
 
        return input_buffer[advance ? input_pos++ : input_pos];
    }
 
    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;
 
        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;
 
        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));
 
        if (negative)
            number = -number;
    }
 
    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
    template<typename T>
    inline void read_char(T &c){
        c = next_char();
    }
}
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const int LOG = 17;

int n;
int dp[MAX][LOG], color[MAX];
vector <int> adj[MAX];
pii opt[MAX], nx_opt[MAX];

void dfs(int u, int p){
    for (int i = 1; i ^ LOG; ++i)
        dp[u][i] = i;
    for (int v : adj[u]){
        if (v == p) continue;
        dfs(v, u);
       
        for (int i = 1; i ^ LOG; ++i)
            dp[u][i] += (opt[v].se == i? nx_opt[v].fi : opt[v].fi);
    }
    opt[u] = nx_opt[u] = make_pair(INF, -1);
    for (int i = 1; i ^ LOG; ++i){
        if (opt[u].fi > dp[u][i]) {
            nx_opt[u] = opt[u];
            opt[u] = make_pair(dp[u][i], i);    
        }
        else if (nx_opt[u].fi > dp[u][i]){
            nx_opt[u] = make_pair(dp[u][i], i);
        }
    }
}


void run_case(){
    IO :: read_int(n);
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        opt[i] = nx_opt[i] = make_pair(0, 0);
        for (int j = 1; j < LOG; j++) dp[i][j] = 0;
        color[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        int u;        
        IO:: read_int(u);
       
        if (u == 0) continue;
        adj[u].push_back(i);
       //adj[i].push_back(u);
//        debug(i, u);
    }
    dfs(1, 0);
/*
    for (int i = 1; i <= n; i++){
       debug(dp[i][1], dp[i][2], dp[i][3]);
    }
    */
    color[1] = 1;
    for (int i = 2; i < LOG; i++)
        if (dp[1][i] < dp[1][color[1]]) 
            color[1] = i;
    printf("%d\n", dp[1][color[1]]);
    /*
    find(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d\n", color[i]);
*/
}

signed main(){

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

