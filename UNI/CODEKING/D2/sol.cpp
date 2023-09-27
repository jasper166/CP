#include "bits/stdc++.h"
#include <clocale>
#include <tuple>

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
const int MAX = 1e5 + 5;
const ll LINF = 1e18 + 5;
const double EPS = 1e-6;

double x, y;
double NOM = 1e18;
int nom, denom;
int LIM = 32767;

int gcd(int a, int b){
    return (b? gcd(b, a % b) : a);
}

int getMin(int a, int b, int dis){
    double t1 = abs((double) a / (double) dis - x / y);
    double t2 = abs((double) b / (double) dis - x / y);
    if (t1 >= EPS && t2 >= EPS){
        return (t1 < t2? a : b);
    }
    else if (t1 >= EPS) return a;
    else if (t2 >= EPS) return b;
    else return min(a, b);

}

void run_case(){
    cin >> x >> y;
    double rez = x / y;
    // cout << gcd(2, 4) << "\n";
    // cout << rez << "\n";
    
    for (int i = 1; i <= LIM; i++){

        double dis = rez * i;
        // if (i == 32767) cout << dis << "\n";
        int d1 = (int) dis;
        int d2 = d1 + 1;
        int d3 = getMin(d1, d2, i);
        int g = gcd(d3, i);
        int D3 = d3 / g;
        int I = i / g;
        if (I > 32767) continue;
        // if (i == 32767) cout << d1 << " " << d2 << " " << d3 << " " << dis << "\n";
        double t3 = abs(((double) d3 / (double) i) - x / y);
        // if (i == 32767) cout << t3 << "\n";
        if (t3 < NOM && t3 >= EPS){
            NOM = t3;
            nom = d3;
            denom = i;
        }

    }
    // cout << NOM << "\n";
    cout << nom << " " << denom << "\n";
}


signed main(){

    int Test = 1;
    cout << fixed << setprecision(10);
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter