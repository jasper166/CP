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
#define TASK "OLP121"
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
const int MAX = 1e6 + 5;

int n , q , a[MAX];
struct node{
    int mini ;
    ll val = 0;
    node(){
        mini = -1;
        val = 0;
    }
}st[MAX * 4];

void build(int l, int r, int id){
    if(l == r){
        st[id].mini = st[id].val = a[l];
        return ;
    }
    int mid = (l+r) / 2;
    build(l , mid , id * 2);
    build(mid + 1, r , id * 2 + 1);

    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
    st[id].mini = min(st[id * 2].mini , st[id * 2 + 1].mini);
}

bool update(int l, int r, int id, int u, int v, int val, int target){
    if(l > v || u > r || st[id].mini > target)
        return false; 
    
    if(l == r){
        st[id].mini = st[id].val = val;
        return true;
    }

    int mid =  (l+r) / 2;
    if(update(l , mid , id * 2 , u , v , val , target)){
        st[id].mini = min(st[id * 2].mini , st[id  * 2 + 1].mini);
        st[id].val = st[id * 2].val + st[id * 2 + 1].val;
        return true;
    }
    
    if(update(mid + 1, r , id * 2 + 1 , u  , v , val , target)){
       st[id].mini = min(st[id * 2].mini , st[id  * 2 + 1].mini);
       st[id].val = st[id * 2].val + st[id * 2 + 1].val;
       return true;
    }

    st[id].mini = min(st[id * 2].mini , st[id  * 2 + 1].mini);
    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
    return false;
}

int get_min(int l ,int r ,int id , int u ,int v){
    if(l > v || u > r)
        return INF;
    if(u <= l && r <= v)
        return st[id].mini;
    int mid = (l+r) / 2;
    return min(get_min(l , mid , id * 2 , u , v) , get_min(mid + 1 , r, id * 2 + 1 , u , v));
}

ll get(int l ,int r , int id , int u ,int v){
    if( l > v || u > r)
        return 0;
    if(u <= l && r <= v)
        return st[id].val;

    int mid = (l+r) / 2;
    return get(l , mid , id * 2 , u , v) + get(mid + 1 , r, id * 2 + 1 , u, v);
}

void run_case(){
//    cin >> n >> q ;
    IO :: read_int(n, q);
    for(int i = 1 ; i <= n ; i++) IO :: read_int(a[i]);
//        cin  >> a[i];
    build(1 , n , 1);
    int changes = 0;
    for(int i = 1 ; i <= q ; i++){
        int op , u;
//        cin >> op >> u;
        IO :: read_int(op, u);
        if(op  == 1){
            changes += u;
            changes %= n;
            continue;
        }
        int v , w;
//        cin >> v ;
        IO :: read_int(v);
        u -= changes;
        if(u <= 0)
            u += n;
        v -=  changes ;
        if(v <= 0)
            v += n;
        if(op == 2){
//            cin >> w;
            IO :: read_int(w);
            if(u > v){
                int value = get_min(1 , n , 1 , u , n);
                value = min(value , get_min(1 , n , 1 , 1 , v ));    
                if(update(1 , n , 1 , u , n , w , value))
                    continue;

                update(1 , n , 1 , 1 , v , w , value);
                continue;
            }
            int value = get_min(1 , n , 1 , u , v);
            update(1  , n , 1 , u , v , w , value);
            continue;
        }
        if(u > v){
              printf("%lld\n", get(1, n, 1, u, n) + get(1, n, 1, 1, v));
//            cout << get(1 , n , 1  , u , n) + get(1 , n , 1 , 1 ,  v)  <<'\n';
            continue;
        }
        printf("%lld\n", get(1, n, 1, u, v));
  //      cout << get(1 , n , 1 , u , v) <<'\n';
    }
    
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

