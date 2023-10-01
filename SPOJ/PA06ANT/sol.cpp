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

int MOD;

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
char a, b;
int k;
vector <int> adj[8];
vector <pii> edge;

void run_case(){
    cin >> a >> b;
    int st = a - 'A';
    int en = b - 'A';
    cin >> k >> MOD;
    //debug(st, en);
    adj[0] = {1, 3, 4};
    adj[1] = {0, 2, 5};
    adj[2] = {1, 3, 6};
    adj[3] = {0, 2, 7};
    adj[4] = {0, 5, 7};
    adj[5] = {1, 4, 6};
    adj[6] = {2, 5, 7};
    adj[7] = {3, 4, 6};

    edge =
    {
        {0, 1}, {0, 3}, {0, 4},
        {1, 0}, {1, 2}, {1, 5},
        {2, 1}, {2, 3}, {2, 6},
        {3, 0}, {3, 2}, {3, 7},
        {4, 0}, {4, 5}, {4, 7},
        {5, 1}, {5, 4}, {5, 6},
        {6, 2}, {6, 5}, {6, 7},
        {7, 3}, {7, 4}, {7, 6}
    };
    Matrix base (24, vector <int> (24, 0));
    Matrix res (1, vector <int> (24, 0));

    for (int i = st * 3; i <= st * 3 + 2; i++){
        res[0][i] = 1;
    }

    // k == 1
    if (k <= 1){
        int ans = 0;
        for (int i = 0; i < 24; i++)
            if (edge[i].se == en)
                ans += (res[0][i]);
        cout << ans << "\n";
        return;
    }

    for (int i = 0; i < 24; i++){
        auto [u, v] = edge[i];
        for (int j = 0; j < 24; j++)
            if (edge[j].se == u){
                if (edge[j].fi == v)
                    base[j][i] = 0;
                else
                    base[j][i] = 1;
            }
    }

//    for (int i = 0; i < 24; i++)
//        for (int j = 0; j < 24; j++){
//            cout << base[i][j] << " \n"[j == 23];
//        }
//
    //debug(res[0]);
    base = Mpow(base, k - 1);
    res = Mmult(res, base);

    //debug(res[0]);
    int ans = 0;
    for (int i = 0; i < 24; i++)
        if (edge[i].se == en){
            ans += (res[0][i]) % MOD;
            ans %= MOD;
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


