#include "bits/stdc++.h"

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
const int MOD = 1e4 + 7;
const int MN = 105;
const int MX = 69984;

int n, a[MN];
vector <pii> primes;
int small[MN][8], big[MN];
int dp[MN][MX][2];

int gcd (int x, int y){ while (y) swap(y, x %= y); return x; }
int lcm (int x, int y){ return x / gcd(x, y) * y; }

bool isPrime(int x){
    FOR(i, 2, sqrt(x))
        if (x % i == 0) return 0;
    return (x >= 2);
}

void getPrime(){
    FOR(i, 2, sqrt(500)){
        if (isPrime(i)){
            int p = 0;
            int x = 500;
            while (x / i){
                x /= i;
                p++;
            }
//            cout << i << "  " << p << "\n";
            primes.emplace_back(i, p);
        }
    }
}

int memoi(int on, int p[8], int got){
     if(((on && big[on] != big[on-1]) || (on == n))) 
        got = 0;

    int id = 0;
    REP(i, 8)
        id = id * (primes[i].se + 1) + p[i];
    int &ans = dp[on][id][got];
    if (ans != -1) return ans;
    if (on == n){
        ans = 1;
        REP(i, 8) 
            REP(j, p[i])
                ans = (ans * primes[i].fi) % MOD;
        return ans;
    }
    //if get
    ans = memoi(on + 1, p, got);
    // if not
    int np[8];
    REP(i, 8) np[i] = max(p[i], small[on][i]);
    ans = (ans + memoi(on + 1, np, 1) * (got? 1 : big[on])) % MOD;
    return ans;        
}


void run_case(){
    cin >> n;
    vector <vector<int>> nums;
    REP(i, n){
        int x;
        cin >> x;
        vector <int> fac(9, 0);
        REP(j, 8){
            while (x % primes[j].fi == 0){
                x /= primes[j].fi;
                fac[j]++;
            }
        }
        fac[8] = x;
        nums.push_back(fac);
    }
    sort(all(nums), [](const vector <int> x, const vector <int> y){
            return x[8] < y[8];
            } 
    );
    REP(i, n){
        REP(j, 8) small[i][j] = nums[i][j];
        big[i] = nums[i][8];
    }
    int p[8];
    REP(i, 8) p[i] = 0;
    FOR(i, 0, n) memset(dp[i], -1, sizeof(dp[i]));
    
    int ans = (memoi(0, p, 0) - 1 + MOD) % MOD;

    cout << ans << "\n";
}


signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    getPrime();
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){
        cout << "Case " << i << ": ";
        run_case();
    }
}
// Codename : Jasper the Otter



