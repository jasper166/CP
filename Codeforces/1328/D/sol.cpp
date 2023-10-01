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
const int MAX = 2e5 + 5;

int n, a[MAX];

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int same = 1;
    for (int i = 2; i <= n; i++) 
        if (a[i] == a[1]) same++;
    if (same == n) {
        cout << "1\n";
        for (int i = 1; i <= n; i++) 
            cout << 1 << " \n"[i == n];
        return;
    }
    if (!(n & 1)){
        cout << "2\n";
        for (int i = 1; i <= n; i++)
            cout << ((i & 1)? 1 : 2) << " \n"[i == n];
        return;
    }
        
    int pos = -1;
    a[n + 1] = a[1];
    for (int i = 1; i <= n; i++)    
        if (a[i] == a[i + 1]){ 
            pos = i;
            break;
        }
      
    if (pos == -1){
        cout << "3\n";
        for (int i = 1; i < n; ++i)
            cout << ((i & 1)? 1 : 2) << " ";
        cout << "3\n";
        return;
    }
    int state = 0;
    for (int j = pos + 1; j <= n; ++j){
        a[j] = state? 2 : 1;
        state ^= 1;
    }
    state = 0;
    for (int j = pos; j; --j){
        a[j] = state? 2 : 1;
        state ^= 1;
    }
    
    cout << "2\n";
    for (int i = 1; i <= n; i++) 
        cout << a[i] << " \n"[i == n];
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
