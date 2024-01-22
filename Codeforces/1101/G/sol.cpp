#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int LG = 32;

int basis[LG];
int sz;
int a[N];
int n;

void add(int cur_vec) {
    for (int i = 0; i < LG; ++i) {
        if ((cur_vec & (1 << i)) == 0) continue;
        if (!basis[i]) {
            ++sz;
            basis[i] = cur_vec;
        }
        cur_vec ^= basis[i];
    }
}   

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum ^= a[i];
        add(sum);
    }
    cout << (sum == 0? -1 : sz) << "\n";
}

/*
    1. -1 if xor_sum = 0
    2. if xor sum of some segments is not 0 -> different xor sum of subset of segment 
    -> each vector of each is different -> answer = numbers of xor basis
    3. any subset of segment can obtainted from xor-ing prefix xor sum
    -> xor basis of all subset producting is equivalent to xor basis of all prefix xor sum
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


