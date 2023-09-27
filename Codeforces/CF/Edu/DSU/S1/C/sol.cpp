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
const int MAX = 2e5 + 5;

int n, m, u, v, w;
int p[MAX], score[MAX], sz[MAX];
string s;


int get(int a){
    return (a == p[a]? a : p[a] = get(p[a]));
}

void add(int a, int b){
    FOR(i, 1, n){
        if (p[i] == a) score[i] += b;
    }
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        p[b] = a;
//        score[b] = score[a];
    }
}

void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) sz[i] = 1, p[i] = i;
    FOR(i, 1, m){
        cin >> s >> u;
        if (s == "join"){
            cin >> v;
            unite(u, v);
        }
        else if (s == "add") {
            cin >> w;
            add(u, w);
//            FOR(i, 1, n) cout << score[i] << " \n"[i == n];
        }
        else {
  //          cout << u << "\n";
            cout << score[u] << "\n";
        }
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


