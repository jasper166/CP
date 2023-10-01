#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstring>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool prime(int x) {
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

const int ms = 69984;
const int mn = 101;
const int MOD = 10007;

std::vector<std::pair<int, int>> primes;
int n;
int small[mn][8], big[mn];
int memo[mn][ms][2];

int dp(int on, int p[8], int got) {
    if(((on && big[on] != big[on-1]) || (on == n))) 
        got = 0;
    int id = 0;
    for(int i = 0; i < 8; i++) {
        id = id * (primes[i].second + 1) + p[i];
    }
    int &ans = memo[on][id][got];
    if(ans != -1) return ans;
    if(on == n) {
        ans = 1;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < p[i]; j++) {
                ans = ans * primes[i].first % MOD;
            }
        }
        return ans;
    }
    // not getting
    ans = dp(on+1, p, got);
    // getting
    int p2[8];
    for(int i = 0; i < 8; i++) {
        p2[i] = std::max(p[i], small[on][i]);
    }
    ans = (ans + dp(on+1, p2, 1) * (got ? 1 : big[on])) % MOD;
    return ans;
}

void solve() {
    std::cin >> n;
    std::vector<std::vector<int>> numbers;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        std::vector<int> wtf(9, 0);
        for(int j = 0; j < 8; j++) {
            while(x % primes[j].first == 0) {
                x /= primes[j].first;
                wtf[j]++;
            }
        }
        wtf[8] = x;
        numbers.push_back(wtf);
    }
    std::sort(numbers.begin(), numbers.end(), [](const std::vector<int> &v1, const std::vector<int> &v2) {
        return v1[8] < v2[8];
    });
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 8; j++) {
            small[i][j] = numbers[i][j];
        }
        big[i] = numbers[i][8];
    }
    int p[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i <= n; i++) {
        memset(memo[i], -1, sizeof memo[i]);
    }
    std::cout << (dp(0, p, 0) + MOD - 1) % MOD << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    //int states = 1;
    for(int i = 2; i * i <= 500; i++) {
        if(prime(i)) {
            int e = 0;
            int x = 500;
            while(x / i > 0) {
                x /= i;
                e++;
            }
            //std::cout << "for " << i << " got " << e << std::endl;
            primes.emplace_back(i, e);
            //states *= e + 1;
        }
    }
    //std::cout << primes.size() << std::endl;
    //std::cout << states << std::endl;
    int t;
    std::cin >> t;
    for(int i = 1; i <= t; i++) {
        std::cout << "Case " << i << ": ";
        solve();
    }
}