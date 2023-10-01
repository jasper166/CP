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
#define TASK "OLP61"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

string s;
int n, q;
int BASE = 31;
// check panlindrome by hash value of prefix and suffix;
using ull = unsigned long long;
ull p[MAX];

struct Fenwick{
    ull f[MAX];
    void update(int x, ull val){
        for (; x <= n; x += (x & (-x))){
            f[x] += val;
        }
    }
    ull get(int x){
        ull sum = 0;
        for (; x; x -= (x & (-x)))
            sum += f[x];
        return sum;
    }
} pref, suff;


void prepare(){
    n = s.size();
    s = '$' + s;
    
    p[0] = 1;
    for (int i = 1; i < MAX; i++){
        p[i] = p[i - 1] * BASE;
    }
    
    for (int i = 1; i <= n; i++){
        pref.update(i, (s[i] - '0' + 1) * p[i]);
        suff.update(i, (s[i] - '0' + 1) * p[n - i + 1]);
    }

}

void run_case(){
    cin >> s >> q;
    prepare();
    /*
    for (int i = 1; i <= n; i++)
        cout << p[i] << " \n"[i == n];
    */
    for (int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        ull P = pref.get(r) - pref.get(l - 1);
        ull S = suff.get(r) - suff.get(l - 1);
        if (n - r - l + 1 >= 0)
            cout << (S == P * p[n - r - l + 1]? "YES" : "NO");
        else 
            cout << (P == S * p[r + l - 1 - n]? "YES" : "NO");
        cout << "\n";
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
