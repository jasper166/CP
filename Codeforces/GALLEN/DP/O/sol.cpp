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

int n, k;
int a[MAX];
int pre[MAX];

bool isOk(int l, int r){
    int cur = pre[r] - pre[l - 1];
    return (cur <= k);
}

void run_case(){
	cin >> n >> k;	
    FOR(i, 1, n) cin >> a[i];
    pii ans = {-1, -2};
    FOR(i, 1, n) pre[i] = pre[i - 1] + (a[i] == 0);
    debugArr(pre, 0, n);
    bool possible = 0;
    FOR(i, 1, n){
        int l = i, r = n;
        while (l <= r){
            int m = (l + r) / 2;
          //  if (i == 4) cout << m << "\n";
            if (isOk(i, m)){
                l = m + 1;
                debug(m);
                if (m - i > ans.se - ans.fi) possible = 1, ans = {i, m};
            }
            else 
                r = m - 1;
        }
    }

    auto [l, r] = ans;
    debug(ans);
    cout << (possible? r - l + 1 : 0) << "\n";
    FOR(i, 1, n){
        if (l <= i && i <= r) 
            cout << "1 ";
        else
            cout << a[i] << " ";
    }
    cout << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

