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

#ifdef LOCAL
#include "debug.h"
#define TASK "OLP5"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif
//FAST IO
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
}

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

using ull = unsigned long long;

int a[MAX];
int n, q;

struct fenwick_2D{
    ull f[MAX], g[MAX];
    
    void update_f(int x, ull val){
        for (; x <= n; x += (x & (-x)))
            f[x] += val;
    }
    
    void update_g(int x, ull val){
        for (; x <= n; x += (x & (-x)))
            g[x] += val;
    }

    void update_range(int l, int r, ull val){
        update_f(l, val);
        update_f(r + 1, -val);
        update_g(l, val * (l - 1));
        update_g(r + 1, -val * r);
    }

    ull get_f(int x){
        ull ans = 0;
        for (; x; x -= (x & (-x)))
            ans += f[x];
        return ans;
    }

    ull get_g(int x){
        ull ans = 0;
        for (; x; x -= (x & (-x)))
            ans += g[x];
        return ans;
    }

    ull sum (int x) {
        return get_f(x) * x - get_g(x);
    }

    ull rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

fenwick_2D bit;


void run_case(){
    // cin >> n;
    IO:: read_int(n);
    // cout << n << " " << q << "\n";

    for (int i = 1; i <= n; i++){
        // cin >> a[i];
        IO:: read_int(a[i]);
        bit.update_range(i, i, a[i]);
    }
    // cin >> q;
    IO:: read_int(q);
    // bit.update_range(1, 2, 2);
    // cout << bit.rangeSum(1, n - 1) << "\n";
    // cout << bit.pref(1, n) << "\n";
    for (int i = 1; i <= q; i++){
        int op, x, l, r;
        // cin >> op;
        IO:: read_int(op);
        if (op == 1){
            // cin >> l >> r >> x;
            IO:: read_int(l, r, x);
            bit.update_range(l, r, x);
        }
        else {
            // cin >> l;
            IO:: read_int(l);
            // cout << l << " " << r << "\n";
            // cout << bit.rangeSum(l, l) << "\n";
            printf("%lld\n", bit.rangeSum(l, l));
        }
    }
}

signed main(){
    // cin.tie(0) -> sync_with_stdio(0);
/*
    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
  */  
    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
