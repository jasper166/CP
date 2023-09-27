#include "bits/stdc++.h"
// @Jasper
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

#ifdef LOCAL
#include "debug.h"
#define TASK "OLP59"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const int BASE = 31;
using ull = unsigned long long;

int n;
string s, t;

ull S[MAX], T[MAX], pw[MAX];

inline void prepare(){
    pw[0] = 1;
    for (int i = 1; i < MAX; i++)
        pw[i] = pw[i - 1] * BASE;
}

ull get(int i, int j, int op){
    if (op == 1)
        return S[j] - S[i - 1] * pw[j - i + 1];
    else
        return T[j] - T[i - 1] * pw[j - i + 1];
}

bool ok(int i, int j){
   // debug(i, j);
//   assert(i <= j);
    if (i > j) return 0;
    return (get(i, j, 1) == get(n - j + 1, n - i + 1, 2));
}

void run_case(){
    cin >> n >> s;
    t = string(s.rbegin(), s.rend());
    s = '$' + s;
    t = '$' + t;

    S[0] = T[0] = 0;
   
    for (int i = 1; i <= n; i++){
        S[i] = S[i - 1] * BASE + s[i] - 'a' + 1;
        T[i] = T[i - 1] * BASE + t[i] - 'a' + 1;
    }
    int ans = -1;
   
    for (int i = 1; i <= n; i++){
        //even case
        int l = 0, r = min(n - i, i);
        while (l <= r){
            int m = (l + r) / 2;
//            cout << m << "\n";
            if (ok(i - m + 1, i + m)){
                ans = max(ans, 2 * m);
                l = m + 1;
            }
            else 
                r = m - 1;
        }
        //odd
   
        l = 0, r = min(n - i, i);
        while (l <= r){
            int m = (l + r) >> 1;
            if (ok(i - m, i + m)){
                ans = max(ans, 2 * m + 1);
                l = m + 1;
            }
            else
                r = m - 1;
        }
        
    }
    
        cout << ans << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    prepare();

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}





