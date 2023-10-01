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
const int MAX = 1e6 + 5;

int x, n, y;
pii c[4];


void run_case(){
    cin >> n;
    REP(i, 3)
        cin >> c[i].fi >> c[i].se;
    cin >> x >> y;
    sort(c, c + 3);

    if(c[0].fi == 1 && c[0].se == 1  && c[1].fi == 1 && c[1].se == 2 && c[2].fi == 2 && c[2].se == 1){
        if(x != 1 && y != 1)
            cout << "NO" << "\n";
        else 
            cout << "YES" << "\n";     
    }else 
        if(c[0].fi == n - 1 && c[0].se == 1  && c[1].fi == n && c[1].se == 1 && c[2].fi == n && c[2].se == 2){
            if(x != n && y != 1)
                cout << "NO" << "\n";
            else 
                cout << "YES" << "\n";     
    }else 
        if(c[0].fi == 1 && c[0].se == n - 1  && c[1].fi == 1 && c[1].se == n && c[2].fi == 2 && c[2].se == n){
            if(x != 1 && y != n)
                cout << "NO" << "\n";
            else 
                cout << "YES" << "\n";     
    }else 
        if(c[0].fi == n - 1 && c[0].se == n  && c[1].fi == n && c[1].se == n - 1 && c[2].fi == n && c[2].se == n){
            if(x != n && y != n)
                cout << "NO" << "\n";
            else 
                cout << "YES" << "\n";     
    }else 
        if((x - c[0].fi) % 2 == 0 && (y - c[0].se) % 2 == 0){
            cout << "YES" << "\n";
    }else
        if((x - c[1].fi) % 2 == 0 && (y - c[1].se) % 2 == 0){
            cout << "YES" << "\n";
    }else
        if((x - c[2].fi) % 2 == 0 && (y - c[2].se) % 2 == 0){
            cout << "YES" << "\n";
    }else 
        cout << "NO" << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

