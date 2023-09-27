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
const int MAX = 1e2 + 5;

int n, m;
int a[MAX][MAX];


void run_case(){
	cin >> n;
    vector <int> ret;

    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j], ret.push_back(a[i][j]);
    sort(all(ret));
    int j = 0;
    int L = 1, R = n, D = 1, U = n;

    while (L <= R && D <= U){
        FOR(i, L, R) 
           a[D][i] = ret[j++];
        D++;

        FOR(i, D, U) 
            a[i][R] = ret[j++];
        R--;

        if (D > U || L > R) break;

        FORD(i, R, L) 
            a[U][i] = ret[j++];
        U--;

        FORD(i, U, D) 
            a[i][L] = ret[j++];
        L++;
    }
    FOR(i, 1, n) FOR(j, 1, n) cout << a[i][j] << " \n"[j == n];
    cout << "\n";
}


signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}



