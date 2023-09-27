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
const int MAX = 3e5 + 5;

int p[MAX], sz[MAX], mi[MAX], ma[MAX];
int n, m, u, v;
string s;

void init(){
    FOR(i, 1, n) sz[i] = 1, p[i] = i, mi[i] = i, ma[i] = i;
    
}
int get(int a){
    return (a == p[a]? a : p[a] = get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if (a != b){
        if (sz[a] < sz[b])
            swap(a, b);
        sz[a] += sz[b];
        p[b] = a;
        ckmin(mi[a], mi[b]);
      //  ckmin(mi[b], mi[a]);
        ckmax(ma[a], ma[b]);
      //  ckmax(ma[b], max(ma[a], ma[b]));
    }
}

void run_case(){
    cin >> n >> m;
    init();
    
    FOR(i, 1, m){
        cin >> s;
        if (s == "union"){
            cin >> u >> v;
            unite(u, v);
        }
        else{
            cin >> u;
            u = get(u);
            cout << mi[u] << " " << ma[u] << " " << sz[u] << "\n";   
        }
    }

    /*
    FOR(i, 1, n) cout << p[i] << " \n"[i == n];
    FOR(i, 1, n) cout << mi[i] << " \n"[i == n];
        FOR(i, 1, n) cout << ma[i] << " \n"[ i== n];
    */
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



