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
const int MOD = 2012;
const int MAX = 1e6 + 5;

using Matrix = vector < vector < int >>;
Matrix Mmult(Matrix A, Matrix B){
    int N = A.size();
    int M = A[0].size();
    int P = B[0].size();
    assert(A[0].size() == B.size());
    Matrix ans (N,  vector <int> (P, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < P; j++)
            for (int k = 0; k < M; k++){
                ans[i][j] += A[i][k] * B[k][j] % MOD;
                ans[i][j] %= MOD;
            }
    return ans;
}

Matrix Mpow(Matrix A, int x){
    int N = A.size();
    assert(A[0].size() == A.size());
    Matrix ans (N, vector <int> (N, 0));
    for (int i = 0; i < N; i++)
        ans[i][i] = 1;
    while (x){
        if (x & 1) ans = Mmult(ans, A);
        A = Mmult(A, A);
        x >>= 1;
    }
    return ans;
}
    
int n, x, p;
vector <pii> edge;

void run_case(){
    cin >> n >> x >> p;
    x--;
    Matrix res (1, vector <int> (6 * n, 0));
    Matrix base (6 * n, vector <int> (6 * n, 0));
    
    edge.resize(6 * n);
    for (int i = 0; i < 6 * n; i += 3){
        int c = i / 3;
//        debug(c);
        edge[i].fi = edge[i + 1].fi = edge[i + 2].fi = c;
        if (c < n){
            edge[i].se = (c + n - 1) % n;
            edge[i + 1].se = (c + n + 1) % n;
            edge[i + 2].se = (c + n);
        }
        else {
            edge[i].se = (c + n - 1) % n + n;
            edge[i + 1].se = (c + n + 1) % n + n;
            edge[i + 2].se = (c + n) % n;
        }
  //      debug(edge[i], edge[i + 1], edge[i + 2]);
    }
    for (int i = 0; i < 6 * n; i++){
        auto [u, v] = edge[i];
        for (int j = 0; j < 6 * n; j++){
            if (edge[j].se == u){
                if (edge[j].fi != v)
                    base[j][i] = 1;
                else
                    base[j][i] = 0;
            }
        }
    }
    /*
        for (int i = 0; i < 24; i++)
            for (int j = 0; j < 24; j++){
                cout << base[i][j] << " \n"[j == 23];
        }
*/
    res[0][0] = res[0][1] = res[0][2] = 1;
    
    res = Mmult(res, Mpow(base, p - 1));
    int ans = 0;
    for (int i = 0; i < 6 * n; i++){
        if (edge[i].se == x){
            ans += (res[0][i] % MOD);
            ans %= MOD;
        }
    }
    cout << ans << "\n";
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

