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

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

class Point{
    double x, y;
    public: 
       // Point ();
       // Point (double x, double y);
//        Point (const Point &p);
        double getX(){
            cin >> x;
            return x;
        }
        double getY(){
            cin >> y;
            return y;
        }
        double distance(Point a, Point b){
            return (double) (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
        }
};


int n;

signed main(){
    cout << fixed << setprecision(2);
    cin >> n;
    Point arr[n + 1];
    for (int i = 1; i <= n; i++){
        arr[i].getX();
        arr[i].getY();
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            double answer = arr[i].distance(arr[i], arr[j]);
            cout << answer << " \n"[j == n];
        }
    }
}


