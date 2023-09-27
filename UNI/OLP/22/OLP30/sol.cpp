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
#define TASK "OLP30"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int nRow, nCol;
vector <pii> state;
int counting(int col){
    int ans = 0;
    for (int maskC1 = 0; maskC1 < (1 << col); maskC1++)
        for (int maskC2 = 0; maskC2 < (1 << col); maskC2++){
            bool ok = 1;
            for (int i = 0; i < col - 2; i++){
                if ((maskC1 & (1 << i)) && (maskC2 & (1 << (i + 2))))
                    ok = 0;
                if ((maskC2 & (1 << i)) && (maskC1 & (1 << (i + 2))))
                    ok = 0;
            }
            if (ok){
                state.emplace_back(maskC1, maskC2);
                ans++;
            }
            ans %= MOD;
        }
    return ans;
}

int f(int preCol_1, int preCol_2, int c){
    if (c == nCol)
        return 0;
    int ans = 0;
//    cout << preCol_1 << " " << preCol_2 << " " << c << "\n"; 
    for (int nx_mask = 0; nx_mask < (1 << nRow); nx_mask++){
        bool ok = 1;
        for (int i = 0; i < nRow - 1; i++){
            if (i < nRow - 1){
                if ((preCol_1 & (1 << i)) && (nx_mask & (1 << (i + 1))))
                    ok = 0;
                if ((preCol_1 & (1 << (i + 1))) && (nx_mask & (1 << i)))
                    ok = 0;
            }
            if (i < nRow - 2){
                if ((preCol_2 & (1 << i)) && (nx_mask & (1 << (i + 2))))
                    ok = 0;
                if ((preCol_2 & (1 << (i + 2))) && (nx_mask & (1 << i)))
                    ok = 0;
            }
        }
        if (ok){
  //          cout << nx_mask << "\n";
            ++ans;
            ans %= MOD;
            ans += (f(preCol_2, nx_mask, c + 1) % MOD);
        }
    }
    ans %= MOD;
    return ans;
}


void run_case(){
    cin >> nRow >> nCol;
    state.clear();
    int ans = counting(nRow);
//    int ans  = 0;
    for (auto [r1, r2] : state) ans += f(r1, r2, 2);
    cout << ans << "\n";

//    cout << m << " " << counting(m) << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
/*
    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
  */  
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




