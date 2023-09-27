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
#define TASK "INP3"
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
const int MAX = 2e5;
const int K = 30;

int trie[1 + MAX * K][2], cnt;
int n;

void update(int val){
    int x = 1;
    for (int b = 1 << K; b; b >>= 1){
        int j = ((val & b) != 0);
        if (!trie[x][j]) trie[x][j] = ++cnt;
        x = trie[x][j];
    }
}

int query(int val){
    int x = 1;
    for (int b = 1 << K; b; b >>= 1){
        int j = ((val & b) != 0);
        if (trie[x][j ^ 1]){
            j ^= 1;
            val |= b;
        }
        else 
            val &= ~b;

        x = trie[x][j];
    }
    return val;
}



void run_case(){
//    cin >> n;
    IO :: read_int(n);
    int x = 0, ans = 0;
    cnt = 1;

    for (int i = 0; i <= (n * K); i++) for (int j = 0; j < 2; j++) trie[i][j] = 0;
    for (int i = 1; i <= n; i++){
        update(x);
        int a;
        IO :: read_int(a);
        x ^= a;
        ans = max(ans, query(x));
    }
//    cout << ans << "\n";
    printf("%d\n", ans);
}

signed main(){
 //   cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

