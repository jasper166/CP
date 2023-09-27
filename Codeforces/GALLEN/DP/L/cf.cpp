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
#define PER(i, b) for(int i = b - 1; i >= 0; i--a
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

int n;
ll a[MAX], b[MAX];
vector <ll> fire, ice;
void run_case(){
        cin >> n;
        REP(i, n) cin >> a[i];
        REP(i, n) cin >> b[i];
        fire.clear();
        ice.clear();
        REP(i, n) {
            if(a[i])
                ice.push_back(b[i]);
            else
                fire.push_back(b[i]);
        }
        sort(all(fire));
        sort(all(ice));
        ll ans = 0;
        int F = fire.size() - 1, I = ice.size() - 1;
        if(F >= 0 && I >= 0 && F > I) {
            int state = 1;
            while (F >= 0 && I >= 0) {
                if(!state) {
                    ans+=ice[I--] * 2;
                    state = 1;  
                }
                else {
                    ans += fire[F--] * 2;
                    state = 0;
                }
            }
        } 
        else if(F >= 0 && I >= 0 && F < I){
            int state = 1;
            while(F >= 0 && I >= 0) {
                if(state) {
                    ans += ice[I--] * 2;
                    state = 0;
                } 
                else {
                     ans += fire[F--] * 2;
                    state = 1;
                }
            }
        } 
        else if(F >= 0 && I >= 0 && F == I) {
            if(fire[0] <= ice[0]) {
                int state = 1;
                while(F >= 0 && I >= 0) {
                    if(state) {
                        ans += ice[I--] * 2;
                        state = 0;
                    }
                    else {
                        ans += fire[F--] * 2;
                        state = 1;
                    }
                }
            } else{
                int state = 1;
                while(F >= 0 && I >= 0) {
                    if(!state) {
                        ans += ice[F--] * 2;
                        state = 1;    
                    }
                    else {
                        ans += fire[F--] * 2;
                        state = 0;
                    }
                }
            }
        }
        while (F) ans += fire[F--];
        while (I) ans += ice[I--];
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


