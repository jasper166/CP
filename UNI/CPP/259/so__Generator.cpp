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

random_device rd; // obtain a random number from hardware
mt19937 gen(rd()); // seed the generator


int Rand(int l, int r){
    uniform_int_distribution<> distr(l, r); // define the range
    return distr(gen);
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    srand(time(0));
    // int n = Rand(2, 9);
    // int m = Rand(2, 9);
    // cout << n <<  " " << m << "\n";
    // string A;
    // A.resize(n);
    // string B;
    // B.resize(m);
    // A[0] = (char) (Rand(1, 9) + '0');
    // B[0] = (char) (Rand(1, 9) + '0');
    // for (int i = 1; i < n; i++) A[i] = (char) (Rand(0, 9) + '0');
    // for (int i = 1; i < n; i++) B[i] = (char) (Rand(0, 9) + '0');
    int A = Rand(1, INF);
    int B = Rand(1, INF);
    cout << A << "\n";
    cout << B << "\n";

}
// Codename : Jasper the Otter




