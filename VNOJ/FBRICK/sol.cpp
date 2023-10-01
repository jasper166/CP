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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
//const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, MOD, X;
using Matrix = vector < vector < int > >;

Matrix Mmult(Matrix A, Matrix B){
    
    assert (A[0].size() == B.size());
    int N = A.size();
    int M = A[0].size();
    int P = B[0].size();

    Matrix res(N, vector <int> (P, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < P; j++)
            for (int k = 0; k < M; k++){
                res[i][j] += (A[i][k] * B[k][j] + MOD) % MOD;
                res[i][j] %= MOD;
            }
    return res;
}

Matrix Mpow(Matrix A, int x){
    assert(A[0].size() == A.size());
    int N = A.size();
    Matrix res(N, vector <int> (N, 0));
    for (int i = 0; i < N; i++)
        res[i][i] = 1;
    while (x){
        if (x & 1)
            res = Mmult(res, A);
        A = Mmult(A, A);
        x >>= 1;
    }
    return res;
}

void run_case(){
    cin >> X >> n >> MOD;
    int Y = -4 * X;
    while (Y < 0) Y += MOD;
    Y %= MOD; 
    Matrix base = 
    {
        {1, 0, 0, 0},
        {(4 * X * X + MOD) % MOD, (4 * X * X + MOD) % MOD, 2 * X % MOD, 1},
        {Y, Y, -1, 0},
        {1, 1, 0, 0}
    };
    Matrix res = 
    {
        {(1 + X * X + MOD) % MOD, (X * X + MOD) % MOD, X % MOD, 1}
    };
    base = Mpow(base, n - 2); 
    res = Mmult(res, base);
    cout << res[0][0] << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


