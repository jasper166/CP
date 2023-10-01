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
const int MAX = 1e3 + 5;

int n;
int a[MAX];
bool unfixed[MAX];

bool isSort(){
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}


void run_case(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)
        if (a[i] != i) unfixed[i] = 1;
    

    vector <int> ans;
    for (int i = 0; i < 2 * n; i++){
        if (isSort()) break;
        
        int mex = n;
        vector <bool> fmex(n + 1, 0);
        for (int j = 0; j < n; j++) 
            fmex[a[j]] = 1;
        for (int j = 0; j < n; j++)
            if (!fmex[j]){
                mex = j;
                break;
            }
        debug(mex);
        
        if (mex == n){
            for (int j = n - 1; j >= 0; j--)
                if (unfixed[j]){
                    a[j] = mex;
                    ans.push_back(j + 1);
                    unfixed[j] = 0;
                    break;
                }
        }
        else{
            a[mex] = mex;
            ans.push_back(mex + 1);
            unfixed[mex] = 0;
        }
        debugArr(a, 0, n - 1);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < (int) ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
    debugArr(a, 0, n - 1);
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


