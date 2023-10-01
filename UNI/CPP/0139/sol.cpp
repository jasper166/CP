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
bool prime[MAX + 1];
int d[MAX + 1];
int n;

void sieve(){
    FOR(i, 2, MAX){
        prime[i] = 1;
        if (i % 2 == 0) d[i] = 2;
        else d[i] = i;
    }
    for (int i = 2; i * i <= MAX; i++){
        if (prime[i])
            for (int j = i * i; j <= MAX; j += i) prime[j] = 0;
    }
    for (int i = 2; i * i <= MAX; i++){
        if (d[i] == i)
            for (int j = i * i; j <= MAX; j += i) d[j] = i;
    }
}

bool smith(){
    int m = n;
    auto dd = [&] (int x){
        int res = 0;
        while (x){
            res += x % 10;
            x /= 10;
        }
        return res;
    };
    int dsum = dd(m);
    int usum = 0;
    while (n != 1){
        usum += dd(d[n]);
        n /= d[n];
    }
//    cout << dsum << " " << usum << "\n";
    return (usum == dsum);
}


void run_case(){
    cin >> n;
    cout << ((!prime[n] && smith())? "YES" : "NO") << "\n";
   
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
   
    sieve();
//    FOR(i, 1, 10) cout << i << " "  << prime[i] << " " << d[i] << "\n";
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



