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
/*
bool prime[MAX + 1];
void sieve(){
    FOR(i, 2, MAX) prime[i];
    FOR(i, 2, sqrt(MAX)) 
        if (prime[i]) 
            for (int j = i * i; j <= MAX; j += i) prime[j] = 0;
    
}
*/
bool prime(int x){
    FOR(i, 2, sqrt(x)) if (x % i == 0) return 0;
    return (x >= 2);
}

void run_case(){
    cin >> n;
    int phi = n;
    int i = 2;
    while (n != 1) {
        if (n % i == 0){
            phi = phi / i * (i - 1);
            while (n % i == 0) n /= i;
        }
        i++;
    }
    cout << prime(phi) << "\n";
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



