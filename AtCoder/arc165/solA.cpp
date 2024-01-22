#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const int N = sqrt(1e9) + 5;
bool pr[N];
vector <int> primes;
void prepare() {
    memset(pr, 1, sizeof pr);
    for (int i = 2; i < N; ++i) {
        if (pr[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < N; j += i)
                pr[j] = 0;
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    prepare();

    int Test; 
    cin >> Test;
    while (Test--) {
        int n;
        cin >> n;
        // if (n is a prime or a power of a prime) -> No
        // if n can be expressed as n / 2 + n / 3 + 1...1 -> n >= 6 Yes
        int _n = n;
        map <int, int> d;
        for (int i : primes) {
            if (_n % i == 0) {
                while (_n % i == 0) {
                    d[i]++;
                    _n /= i;
                }
            }
        }
        if (_n != 1) d[_n]++;
        if (d.size() == 1) {
            cout << "No\n";
            continue;
        }
        cout << (n >= 6? "Yes\n" : "No\n");
    }    
}

