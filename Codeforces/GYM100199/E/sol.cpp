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
#define TASK "1311D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, p;
using type = int;

struct Matrix {
    vector < vector <type> > a;
    int N() const {return a.size();};
    
    Matrix (int N) : a(N, vector <type> (N)) { };
    Matrix () = default;
    Matrix (const vector <vector <type>> &d) : a(d) { };

    Matrix operator *(const Matrix b){
        Matrix a = *this;
        Matrix c(a.N());

        for (int i = 0; i < a.N(); i++)
            for (int j = 0; j < a.N(); j++)
                for (int k = 0; k < a.N(); k++){
                    c.a[i][j] += a.a[i][k] % MOD * (b.a[k][j] % MOD);
                    c.a[i][j] %= MOD;
                }
        return c;
    }
    Matrix pow(int exp){
        Matrix base = *this;
        Matrix ans ({{1, 0}, {0, 1}});
        while (exp){
            if (exp & 1) ans = ans * base;
            base = base * base;
            exp >>= 1;
        }
        return ans;
    }
};


void run_case(){
//    cin >> n >> m >> p;
    Matrix a({{0, 1}, {1, 1}});
    cin >> n;
    Matrix ans = a;
    ans = a.pow(n - 1);
    cout << (ans.a[0][0] + ans.a[0][1]) % MOD << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
//
 //   if (fopen(TASK ".inp", "r"))
  /*
    freopen("nice.in", "r", stdin);
    freopen("nice.out", "w", stdout);
    */

    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




