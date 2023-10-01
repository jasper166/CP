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
#define TASK "OLPT1"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const int LOG = 18;

int n, d;
pii a[MAX];
int f[LOG][MAX], lg[MAX];
int b[MAX];

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

int get(int l, int r){
    if (l > r) return 0;

    int k = lg[r - l + 1];
    return max(f[k][l], f[k][r - (1 << k) + 1]);
}

void run_case(){
//    cin >> n >> d;
    IO :: read_int(n, d);  
    for (int i = 1; i <= n; i++){
//        cin >> a[i].fi,  >> a[i 
        IO :: read_int(a[i].fi, a[i].se);
    }  
    
    lg[1] = 0;
    for (int i = 2; i < MAX; i++) lg[i] = lg[i / 2] + 1;
    
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) f[0][i] = a[i].se, b[i] = a[i].fi;
    
    for (int k = 1; k < LOG; k++)
        for (int i = 1; i <= n; i++)
            f[k][i] = max(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int k;
        k = lower_bound(b + 1, b + 1 + n, a[i].fi - d) - b;
        if (get(k, i - 1) < 2 * a[i].se) continue;
        k = lower_bound(b + 1, b + 1 + n, a[i].fi + d) - b;
        if (get(i + 1, k) < 2 * a[i].se) continue;
        ans++;
    }
    printf("%d\n", ans);
}

signed main(){
    //cin.tie(0) -> sync_with_stdio(0);
    

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


