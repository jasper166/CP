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

#ifdef LOCAL
#include "debug.h"
#define TASK "1311D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 55;

ll F[MAX][MAX], nk[MAX];
ll inv[MAX];
ll C[MAX][MAX];


void prepare() {

    for(int i = 0; i < MAX; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
    }
    for(int i = 2; i < MAX; i++) {
        for(int j = 1; j < i; j++){
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
     
    inv[0] = inv[1] = 1;

    for(int i = 2; i < MAX; i++) 
        inv[i] = (1LL * (MOD / i) * inv[MOD % i] * 1LL) % MOD + MOD;

    F[0][0] = 1;
    F[1][0] = F[1][1] = inv[2];
    
    for(int i = 2; i < MAX - 1; i++) {
        F[i][0] = i + 1;

        for(int j = 0;j <= i - 1; j++)
            F[i][0] = (F[i][0] - 1LL * C[i + 1][j] * F[j][0]) % MOD;
        
        F[i][0] = (F[i][0] * 1LL * inv[i + 1] + MOD) % MOD;
        
        for(int j = 1; j <= i; j++) 
            F[i][j] = ((((F[i - 1][j - 1] * 1LL * i) % MOD) * 1LL * inv[j+1]) % MOD);
    }
}

void NK(ll n, int k) {
    nk[0] = n;
    for(int i = 1; i <= k + 2; i++)
        nk[i] = (nk[i - 1] * n) % MOD;
}

ll f(int k) {
    ll ans = 0;
    
    for(int i = 0;i < k + 1; i++) 
        ans = (ans + 1LL * F[k][i] * nk[i]) % MOD;
    
    return ans;
}

int n, k;

void run_case(){
    cin >> n >> k;
    NK(n, k);

    ll ans = f(k);
    ans = (ans + MOD) % MOD;
    cout << ans << "\n";
    
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
/*
    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
*/    

    prepare();
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

