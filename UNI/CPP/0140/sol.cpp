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

ll n;

bool isPrime(ll x){
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
   
    return (x >= 2);
}

bool isPerfect(ll x){
    for (int i = 2; i < 33; i++){
        if (isPrime(i)) 
          if (isPrime((1LL * pow(2, i) - 1))){
            if (1LL * pow(2, 2 * i) == (1LL * pow(2, i) + 2 * n)) return 1;
        }
    }
    return 0;
    
}

void run_case(){
    cin >> n;
    cout << isPerfect(n) << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



