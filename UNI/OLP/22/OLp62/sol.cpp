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
#define TASK "olp62"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif
// FAST IO
namespace IO {
    const int BUFFER_SIZE = 1 << 15;
 
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
 
    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
 
        if (input_len == 0)
            input_buffer[0] = EOF;
    }
 
    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();
 
        return input_buffer[advance ? input_pos++ : input_pos];
    }
 
    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;
 
        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;
 
        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));
 
        if (negative)
            number = -number;
    }
 
    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
    template<typename T>
    inline void read_char(T &c){
        c = next_char();
    }
}
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
#define int long long
struct node {
    ll val, lazy;
} st[MAX * 4];

int n, q;
int a[MAX];

void build(int l, int r, int k){
    if (l == r){
        st[k].val = a[l];
        return;
    }
    int m = (l + r) / 2;
    
    build (l, m, 2 * k);
    build(m + 1, r, 2 * k + 1);

    st[k].val = max(st[2 * k].val, st[2 * k + 1].val);
}

void push (int k){
    int add = st[k].lazy;
    st[k * 2].lazy += add;
    st[k * 2].val += add;

    st[k * 2 + 1].lazy += add;
    st[k * 2 + 1].val += add;

    st[k].lazy = 0;
}

void update (int l, int r, int k, int L, int R, int val){
    if (R < l || r < L)
        return;
    if (L <= l && r <= R){
        st[k].val += val;
        st[k].lazy += val;
        return;
    }
    int m = (l + r) / 2;    
    push(k);
   
    update(l, m, 2 * k, L, R, val);
    update(m + 1, r, 2 * k + 1, L, R, val);

    st[k].val = max(st[k * 2].val, st[2 * k + 1].val);
}

int get(int l, int r, int k, int L, int R){
    if (R < l || r < L)
        return -INF;
    if (L <= l && r <= R)
        return st[k].val;
    int m = (l + r) / 2;
    push(k);
    return max(get(l, m, 2 * k, L, R), get(m + 1, r, 2 * k + 1, L, R));
}


void run_case(){
    IO :: read_int(n, q);
    for (int i = 1; i <= n; i++)
        IO :: read_int(a[i]);
        
    
    build(1, n, 1);
    
    for (int i = 1; i <= q; i++){
        int op, l, r, x;
        IO :: read_int(op, l, r);
        if (op == 1)
            printf("%lld\n", get(1, n, 1, l, r));
        else {
            IO :: read_int(x);
            update(1, n, 1, l, r, x);
        }
    }

}

signed main(){

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
