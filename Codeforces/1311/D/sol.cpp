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
#define TASK "1311D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int a, b, c;

int get(int x, int y){
    int val1 = x * (y / x);
    int val2 = x * (y / x + 1);    
    return (2 * y < val1 + val2)? val1 : val2;
}

void run_case(){
    cin >> a >> b >> c;
    
    int min_op = INF;
    tuple <int, int, int> ans;

    for (int i = 1; i <= 2 * a; i++){
        for (int j = i; j <= 2 * b; j += i){
            int k = get(j, c);
            int total = abs(i - a) + abs(j - b) + abs(k - c);
            if (total < min_op && total >= 0){
                //debug(i, j, k, min_op);
                min_op = total;
                ans= make_tuple(i, j, k);
            }
        }
    }
    cout << min_op << "\n";
    auto [i, j, k] = ans;
    cout << i << " " << j << " " << k << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    /*
    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    */
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


