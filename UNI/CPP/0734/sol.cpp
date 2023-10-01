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
const int MAX = 505;

int n, m;
int a[MAX][MAX]; 
int col[MAX];

int getRow(){
    stack <int> st;
    int ans = 0;
    // m = col.size();
    FOR(i, 1, m + 1){
        while (!st.empty() && (i == m + 1 || col[st.top()] >= col[i])){
            int h = col[st.top()];
            st.pop();

            int w;
            if (st.empty())
                w = i;
            else
                w = i - st.top() - 1;
            cout << i << " " << w  <<  " " << h << "\n";
            ckmax(ans, w * h);
        }
        st.push(i);
    }
    return ans;
}


void run_case(){
    cin >> n >> m;
    int ans = 0;
    
     FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
     FOR(i, 1, m) col[i] = 0; 

    //REP(i, n) REP(j, m) cin >> a[i][j];
  //  vector <int> col(m);
    FOR(i, 1, n){

        FOR(j, 1, m){
            if(a[i][j])
                col[j] += a[i][j];
            else 
                col[j] = 0;
        }
        // FOR(j, 1, m) cout << col[j] << " \n"[j == m];
        // cout << getRow() << "\n";
        //if (i == 1) cout <<  getRow();
        int k = getRow();
        cout << k << "\n";
        ckmax(ans, k);
    }
    
    // vector <int> v = {2, 3, 3, 2};
    // cout << getRow(v) << "\n";



    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter


