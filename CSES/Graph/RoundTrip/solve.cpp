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
const int MAX = 1e5 + 5;

int n, m;
vector <int> edges[MAX];
vector <int> trace;
bool vis[MAX];

inline void fk(){
    vector <int> ans;
    map <int, pii> mp;
    trace.push_back(INF);
    reverse(all(trace));
//    for (int i : trace) cout << i << " ";
    FOR(i, 1, (int) trace.size()){
        if (mp[trace[i]].fi){
            FOR(j, mp[trace[i]].fi, i) ans.push_back(trace[j]);
            break;
        }
        else mp[trace[i]].fi = i;
    }
    reverse(all(ans));
    cout << (int) ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    cout << "\n";
    exit(0);

}

bool dfs(int u, int p){
    vis[u] = 1;
    for (int v : edges[u]){
        trace.push_back(v);
        if (!vis[v]){ 
            if (dfs(v, u)) 
                return 1;
        }
        else if (v != p) return 1;
        
       if (!trace.empty())  trace.pop_back();
    }
    return 0;
}


void run_case(){
    cin >> n >> m;
    FOR(i, 1, m){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    FOR(i, 1, n){
        trace.push_back(i);
        if (!vis[i] && dfs(i, 0)){
            fk();
        }
        trace.pop_back();
    }
    puts("IMPOSSIBLE");

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



