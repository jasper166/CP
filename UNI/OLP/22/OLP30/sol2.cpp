#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < ll, ll >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)
#define REP(i, b) for(ll i = 0; i < b; i++)
#define PER(i, b) for(ll i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#ifdef LOCAL
//#include "debug.h"
#define TASK "OLP30"
#else
#define debug(...) 42
#define TASK "prller"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MAX = 1e6 + 5;


ll nRow, nCol;
using Matrix = vector < vector <ll> >;
ll m;
Matrix base;

void prepare(){
    base.assign(1 << nRow, vector <ll> (1 << nRow, -1));
    m = 0;
    for (ll i = 0; i < (1 << nRow); i++){
        for (ll j = 0; j < (1 << nRow); j++){
            bool ok = 1;
            for (ll k = 0; k < nRow - 2 && ok; k++){
                if ((i & (1 << k)) && (j & (1 << (k + 2))))
                    ok = 0;
                if ((i & (1 << (k + 2))) &&(j & (1 << k)))
                    ok = 0;
            }
            if (ok) base[i][j] = m++;
        }
    }
    
}

Matrix operator *(Matrix a, Matrix b){
    ll n = a.size();
    ll m = a[0].size();
    ll p = b[0].size();
    Matrix c(n, vector <ll> (p, 0));
    ll MOD2 = 1LL * MOD * MOD;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < p; j++){    
            ll tmp = 0;    
            for (ll k = 0; k < m; k++){
               tmp += a[i][k] * 1LL * b[k][j];
               if (tmp >= MOD2) tmp -= MOD2;
            }
            c[i][j] = tmp % MOD;
        }
    return c;
}

Matrix pow(Matrix a, ll x){
    Matrix ans(a.size(), vector <ll> (a[0].size(), 0));
    for (ll i = 0; i < a.size(); i++)
        ans[i][i] = 1;
    for (; x; x >>= 1){
        if (x & 1) ans = ans * a;
        a = a * a;
    }
    return ans;
}


void run_case(){
    // cin >> nRow >> nCol;
    scanf("%lld%lld", &nRow, &nCol);
    prepare();
    if (nCol == 1){
        printf("%lld\n", 1LL * (1 << nRow));
        return;
    }
    Matrix state(m, vector <ll> (m, 0));

    for (ll c1 = 0; c1 < (1 << nRow); c1++){
        for (ll c2 = 0; c2 < (1 << nRow); c2++){
            for (ll c3 = 0; c3 < (1 << nRow); c3++){
                ll c12 = base[c1][c2];
                ll c23 = base[c2][c3];
                
                if (c12 != -1 && c23 != -1){
                    bool ok = 1;
//                    cout << c12 << " " << c23 << "\n";
                    for (ll i = 0; i < nRow - 1 && ok; i++){
                        if ((c1 & (1 << i)) && (c3 & (1 << (i + 1))))
                            ok = 0;
                        if ((c1 & (1 << (i + 1))) && (c3 & (1 << i)))
                            ok = 0;
                    }
                    if (ok) state[c12][c23] = 1;
                }
               
            }
        }
    }
    state = pow(state, nCol - 2);
    ll res = 0;
    for (ll i = 0; i < m; i++)
        for (ll j = 0; j < m; j++){
            res += state[i][j];
            res %= MOD;
        }
    res %= MOD;
    printf("%lld\n", res);
    // cout << res << "\n";
}

signed main(){
    // cin.tie(0) -> sync_with_stdio(0);
/*
    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
  */  
    ll Test = 1;
    // cin >> Test;
    scanf("%lld", &Test);
    FOR(i, 1, Test){

        run_case();
    }
}
