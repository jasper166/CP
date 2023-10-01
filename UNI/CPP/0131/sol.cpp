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
const int MAX = 1e6 + 5;

int n;
int d[MAX + 1];
int prime(int i){
    if (i % 2 == 0) return 2;
    FOR(j, 2, sqrt(i)) 
        if (i % j == 0) return j;
    return i;
}
void sieve(){
    FOR(i, 1, 3){
        d[i] = i;
    }
    FOR(i, 4, MAX) d[i] = prime(i); 
    
}


void run_case(){
    cin >> n;
    FOR(i, 1, n) cout << d[i] << " \n"[i == n];
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

        
    sieve();
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter





