#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using ull = unsigned long long;
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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP3"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const int BASE = 131;

set <ull> se;
string s;
int n, m;

void run_case(){
    cin >> n >> m;

    ull pw = 1;
    for (int i = 1; i <= n; i++){
        cin >> s;
        ull h = 0;
        
        for (int j = 0; j < s.size(); j++, pw *= BASE)
            h += 1ULL * s[j] * pw; 
        se.insert(h);
    }

    for (int i = 1; i <= m; i++){
        cin >> s;
        ull h = 0;
        pw = 1;
        for (int j = 0; j < s.size(); j++, pw *= BASE)
            h += 1ULL * s[j] * pw;
        bool ok = 0;
        pw  = 1;
        for (int j = 0; j < s.size(); j++, pw *= BASE){
            h -= 1ULL * s[j] * pw;
            for (char c = 'a'; c <= 'c'; c++){
                if (s[j] == c) continue;
                h += 1ULL * c * pw;
                if (se.find(h) != se.end()){
                    cout << "YES\n";
                    ok = 1;
                    break;
                }
                h -= 1ULL * c * pw;
            }

            if (ok)
              //  cout << "NO\n";
                break;
            
            h += 1ULL * s[j] * pw;
//            pw *= BASE;
        }
        if (!ok) cout << "NO\n";
     /*        
        if (ok)
            cout << "NO\n";
            */
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

