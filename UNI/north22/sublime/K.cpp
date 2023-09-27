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
const int MAX = 1e3 + 5;


int n;
int a[MAX];
bool vis[MAX];

void impossible(){
    cout << "NO\n";
    exit(0);
}

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        if (a[i]){
            vis[i] = 1;
            int l = i - 1;
            int val = a[i];
            int cnt = a[i] - 1;
            while (l >= 1 && cnt > 0){
                if ((a[l] && a[l] != val) || vis[l]) break;
                a[l] = val; 
                vis[l] = 1;
                l--;
                cnt--;
                // cout << l << " ";
            }
            // cout << "\n";
            int r = i + 1;
            // cout << r << "\n";
            while (r <= n && cnt > 0){
                if ((a[r] && a[r] != val) || vis[r]) break;
                a[r] = val;
                vis[r] = 1;
                r++;
                cnt--;
                // cout << "R :" << r << " ";
            }
            i = r - 1;
            if (cnt) impossible();
            // FOR(i, 1, n) cout << vis[i] << " \n"[i == n];
        }
    }
    // FOR(i, 1, n) cout << a[i] << " \n"[i == n];
    FOR(i, 1, n)
        if (!a[i] && ((!a[i + 1] && i + 1 <= n) || (!a[i - 1] && i - 1 >= 1)))
            impossible();
    cout << "YES\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}