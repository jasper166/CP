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
const int MAX = 2e5;
const int K = 30;

int trie[1 + MAX * K][2], cnt;
int n;

void update(int val){
    int x = 1;
    for (int b = 1 << K; b; b >>= 1){
        int j = ((val & b) != 0);
        if (!trie[x][j]) trie[x][j] = ++cnt;
        x = trie[x][j];
    }
}

int query(int val){
    int x = 1;
    for (int b = 1 << K; b; b >>= 1){
        int j = ((val & b) != 0);
        if (trie[x][j ^ 1]){
            j ^= 1;
            val |= b;
        }
        else 
            val &= ~b;

        x = trie[x][j];
    }
    return val;
}



void run_case(){
    cin >> n;
    int x = 0, ans = 0;
    cnt = 1;

    for (int i = 0; i <= (n * K); i++) for (int j = 0; j < 2; j++) trie[i][j] = 0;
    for (int i = 1; i <= n; i++){
        update(x);
        int a;
        cin >> a;
        x ^= a;
        ans = max(ans, query(x));
    }
    cout << ans << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


