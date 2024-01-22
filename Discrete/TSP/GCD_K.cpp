#include "bits/stdc++.h"

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

#ifdef LOCAL
#include "debug.h"
#define TASK "1311D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

// #define int long long

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int * st;
int ans;

int merge (int x, int y) {
    return (__gcd(x, y));
}

void build (int arr[], int n){
    for(int i = 0; i < n; i++)
        st[n + i] = arr[i];
    for(int i = n - 1; i; i--)
        st[i] = merge(st[i << 1],st[ i<< 1 | 1]);
}
int query (int l,int r,int n){
    int gc = 0;
    for(l += n,r += n;l < r; l >>= 1,r >>= 1){
        if(l & 1)
            gc = merge(st[l++], gc);
        if(r & 1)
            gc = merge(st[--r], gc);
    }
    return gc;
}
int helper (int arr[], int n, int g) {
    for(int i = 0; i < n; i++)
        if(arr[i] == g)
            return 1;
        st = new int[n << 1], ans = INT_MAX;
        build(arr, n);
        for (int i = 0; i < n - 1; i++){
            int l = 2,r = n - i;
            while (l <= r){
                int m = (l + r) >> 1;
                int gc = query(i, i + m, n);
                if(gc <= g){
                    if (gc == g) ans = min(ans, m);
                    r = m - 1;
                }
                else
                    l= m + 1;
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }

void run_case(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << helper(a, n, k) << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}



