#include "bits/stdc++.h"
// @Jasper


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

int n, a[MAX];
const int N = 1e7 + 5;
vector <int> p(N);

pii ans[MAX];

void sieve(){
   for (int i = 0; i < N; i++) 
       p[i] = (i & 1)? i : 2;
   for (int i = 2; i <= sqrt(N); i++)
       if (p[i] == i)
           for (int j = i * i; j < N; j += i) p[j] = min(p[j], i);
}

vector <int> divisor(int x){
    vector <int> d;
    int pre = 1;
    while (x != 1){
        if (pre != p[x]){
            d.push_back(p[x]);
            pre = p[x];
   //         cout << pre << "\n";
        }
        x /= p[x];
    }
    return d;
}


void run_case(){
    sieve();
   // cout << prime.size() << "\n";
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], ans[i] = {-1, -1};
   // for (int i = 2; i <= 20; i++) cout << p[i] << " \n"[i == 20];
    
    for (int i = 1; i <= n; i++) {
        vector <int> d = divisor(a[i]);
        debug(d);
        
        if (d.size() == 1) continue;
        int x = d[0];
        ans[i].se = 1;
        while (a[i] % x == 0){
            ans[i].se *= x;
            a[i] /= x;
        }
        ans[i].fi = a[i];
    }
    
    //debug(__gcd(a[1], 210));
    for (int i = 1; i <= n; i++) cout << ans[i].fi << " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << ans[i].se << " \n"[i == n];
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
