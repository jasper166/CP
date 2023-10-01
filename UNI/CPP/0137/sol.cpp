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

ll L, R;
bool prime[MAX + 1];

void sieve(){
    FOR(i, 2, MAX) prime[i] = 1;
    FOR(i, 2, sqrt(MAX))
        if (prime[i]) 
            for (int j = i * i; j <= MAX; j += i) prime[j] = 0;
}

void run_case(){
    cin >> L >> R;
    if (L > R) swap(L, R);
    int cnt = 0;
    int x = sqrt(L);
    if (x * x < L) x++;
    L = x;
    R = sqrt(R);
   // cout << L << " " << R;
    for (int i = L; i <= R; i++){
        if (prime[i]){
//            cout << i << " ";
            cnt++;
        }
    }
    cout << cnt << "\n";
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



