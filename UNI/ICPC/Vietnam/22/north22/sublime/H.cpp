#include "bits/stdc++.h"
// @Jasper x Powder
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
#define el "\n"
#define LL long long
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()

#ifdef LOCAL
#include "debug.h"
#define TASK "61E"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e7 + 5;


int n, q;
int tree[MAX];
void add(int x){
    for(;x < MAX; x += (-x) & x){
        tree[x]++;
    }
}
void del(int x){
    for(;x < MAX; x += (-x) & x){
        tree[x]--;
    }
}
int get(int x){
    int ans = 0;
    for(; x; x -= (-x) & x){
        ans += tree[x];
    }
    return ans;
}
double findd(int x){
    double ans = 0;
    for(int l = 1, r = MAX; l <= r; ){
        int m = (l + r) / 2;
        if(get(m) >= x)
            ans = m, r = m - 1;
        else l = m + 1;
    }   
    return ans;
}
void run_case(){
    cin >> q;
    for(int i = 1; i <= q; i++){
        string type;
        cin >> type;
        if(type == "IN"){
            int x;
            cin >> x;
            add(x);
            n++;
        }else 
        if(type == "OUT"){
            int x;
            cin >> x;
            del(x);
            n--;
        }else{
            if(n & 1){
                cout << findd(n / 2 + 1) << el;
            }else{
                cout << (findd(n / 2) + findd(n / 2 + 1)) / 2 << el;
            }
        }
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;

    FOR(i, 1, Test){

        run_case();
    }
}

// 22
// IN 1
// MEDIAN
// IN 2
// MEDIAN
// IN 3
// MEDIAN
// IN 4
// MEDIAN
// IN 5
// MEDIAN
// OUT 1
// MEDIAN
// IN 6
// MEDIAN
// OUT 2
// MEDIAN
// IN 7
// MEDIAN
// OUT 5
// MEDIAN
// IN 8
// MEDIAN
