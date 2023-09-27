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

int n, q, u, v;
string s;

int par[MAX], sz[MAX];

void init(){
    FOR(i, 1, n) par[i] = i, sz[i] = 1;
}

int get(int a){
    if (a == par[a]) return a;
    return par[a] = get(par[a]);
}

bool same_set(int a, int b){return get(a) == get(b);}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if (a != b){
        if (sz[a] > sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
}


void run_case(){
    cin >> n >> q;
    init();

    while (q--){
        cin >> s >> u >> v;
        if (s == "union") 
            unite(u, v);
        else 
            cout <<  (same_set(u, v)? "YES\n" : "NO\n");
    }

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



