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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N;

struct Point {
    int x, y, id;
};
double dis (Point a, Point b) {
    return (sqrt((a.x - b. x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}
Point *Y;
double closetPair (Point X[], int n){
    if (n == 1)
        return 1e18;
    if (n == 2)
        return dis(X[0], X[1]);
    if (n == 3)
        return min({dis(X[0], X[1]), dis(X[1], X[2]), dis(X[2], X[0])});
    
    int mid = n / 2;
    double dl = closetPair(X, mid);
    double dr = closetPair(X + mid, n - mid);
    double d = min(dl, dr);
    
    vector <Point> S;
    for (int i = 0; i < n; i++){
        if (abs(X[i].x - X[mid].x) < d) 
            S.push_back(Y[i]);
    }
    
    for (int i = 0; i < S.size() - 1; i++){
        for (int j = i + 1; j < S.size() && (S[j].y - S[i].y) < d; j++)
            d = min(d, dis(S[i], S[j]));
    }
    return d;
 }


void run_case(){
    cin >> N;
    Point X[N + 1];
    Y = new Point[N + 1];
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        X[i] = Y[i] = {x, y};
    }
    sort(X, X + N, [] (const Point a, const Point b){
            return a.x < b.x;
            });
    sort(Y, Y + N, [] (const Point a, const Point b){
            return a.y < b.y;
            });

    cout << fixed << setprecision(6) << closetPair(X,N) << "\n";
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
