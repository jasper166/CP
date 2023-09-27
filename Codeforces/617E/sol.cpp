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

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 10;
const int BLOCK_SIZE = 333;

struct query{
    int L, R, id;
};
int n, m, k;
query q[MAX];
int a[MAX];
ll get_answer, ans[MAX];
int cnt[1 << 21];

void remove(int op){
    cnt[a[op]]--;
    get_answer -= cnt[a[op] ^ k];
}
void add(int op){
    get_answer += cnt[a[op] ^ k];
    cnt[a[op]]++;
}

void run_case(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    for (int i = 1; i <= m; i++){
        cin >> q[i].L >> q[i].R;
        q[i].id = i;
        --q[i].L;
    }
    sort(q + 1, q + 1 + m, [](query x, query y){
        return (x.L / BLOCK_SIZE < y.L / BLOCK_SIZE || (x.L / BLOCK_SIZE == y.L / BLOCK_SIZE && x.R < y.R));
            });
    int cur_L = 0, cur_R = 0;
    cnt[0] = 1;
    for (int i = 1; i <= m; i++){
        while (cur_L > q[i].L) add(--cur_L);
        while (cur_R < q[i].R) add(++cur_R);
        while (cur_L < q[i].L) remove(cur_L++);
        while (cur_R > q[i].R) remove(cur_R--);
        ans[q[i].id] = get_answer;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}



