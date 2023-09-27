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
const int MAX = 1e5 + 5;

int n, a[MAX];  

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
   
    int ans = 0;
    for (int val = 30; val >= 0; val--){
        // that already subtract the maximum val in the segment
       
    /*

        int in_val = INF;
        // not subtracting any element
        int ex_val = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] > val){
                in_val = INF;
                ex_val = sum = 0;
                continue;
            }
            if (a[i] == val)
                in_val = ex_val;
            sum += a[i];
            ex_val = min(ex_val, sum);
            ans = max(ans, sum - ex_val - val); 
        }
        */
        int cur = 0;
        for (int i = 1; i <= n; i++){
            cur += a[i];
            if (cur < 0 || a[i] > val)
                cur = 0;
            ans = max(ans, cur - val);
        }
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


