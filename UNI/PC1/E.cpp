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
const ll LINF = 1e18;

int a[MAX], n;
ll b[MAX];
set <int> s;

ll getMax(){
    ll M1 = 1LL, M2 = 1LL;
    int cnt = 0;
    auto it1 = s.begin();
    auto it2 = s.end();
    --it2;
    
    M1 = (*it1);
    it1++;
    M1 *= 1LL * (*it1) * (*it2);

    for (; cnt != 3; cnt++, --it2) M2 *= 1LL * (*it2);

    return max(M1, M2);
}

void run_case(){
    cin >> n;
    s.clear();
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) b[i] = -LINF; 

    for (int i : s) cout << i << " ";

    FOR(i, 1, n){
        s.insert(a[i]);
        if (i <= 2){
            b[i] = 0;
            continue;
        }            
        b[i] = max(b[i], getMax());
        // getMax();
    }
    FOR(i, 1, n) cout << b[i] << " \n"[i == n];
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter


