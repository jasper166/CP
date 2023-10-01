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
const int MAX = 1e5;

vector <int> nums;

bool isValid (int x) {
    vector <int> f(6, 0);
    while (x) {
        f[x % 10]++;
        x /= 10;
    }
    for (auto i : f)
        if (i > 1)
            return 0;
    return 1;
}

void prepare () {
    queue <int> q;
    for (int i = 0; i <= 5; i++) {
        nums.push_back(i);
        if (i)             
            q.emplace(i);
    }
    // debug(nums);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (int i = 0; i <= 5; i++) {
            string y = to_string(x) + (char) (i + '0');
            int Y = stoi(y);
            if (Y > MAX || !isValid(Y))
                continue;
            q.emplace(Y);
            nums.push_back(Y);
        }
    }
    sort(all(nums));
    // debug(nums);
}

int solve (int x) {
    int pos = (int) (lower_bound(all(nums), x) - nums.begin());
    return (nums[pos] == x)? pos + 1 : pos;
}

void run_case(){
    int l, r;
    cin >> l >> r;
    if (l > r) swap(l, r);
    // cout << solve(-1) << "\n";
    // cout << solve(13) << "\n";
    // cout << solve(6) << "\n";
    cout << solve(r) - solve(l - 1) << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    prepare();
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

