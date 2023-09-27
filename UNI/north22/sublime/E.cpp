#include "bits/stdc++.h"
// @Jasper x Powder
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
#define el "\n"
#define LL long long
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
#define int long long 

#ifdef LOCAL
#include "debug.h"
#define TASK "61E"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e4 + 10;

int f[MAX], check[10001][10001];
void init(){
    f[0] = 1;
    for(int i = 1; i < MAX; i++){
        if(i & 1)
            f[i] = f[i / 2];
        else
            f[i] = f[i / 2] + f[i / 2 - 1];
        
        int x = __gcd(f[i], f[i - 1]);
        if((f[i] / x <= 1e4) && (f[i - 1] / x <= 1e4)){
            if(check[f[i - 1] / x][f[i] / x] == 0)
                check[f[i - 1] / x][f[i] / x] = i;
        }
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    init();
    int Test = 1;
    
    FOR(i, 1, Test){
        int p, q;
        while(cin >> p >> q){
            int x = __gcd(p, q);
            p /= x;
            q /= x;
            cout << (check[p][q] ? check[p][q] - 1 : -1) << el;
        }
    }
}
