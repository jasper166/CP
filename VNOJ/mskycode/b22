#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// B22
const int MAX = 1e2 + 5;

int n;
int a[MAX];

void run_case() {
    cin >> n;

    vector <int> d;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            n /= i;
        }
    }
    if (n != 1)
        d.push_back(n);

    int x = 1, y = 1, z = 1;
    for (int &u : d) {
        if (x == 1)
            x *= u;
        else if (y == 1 || x == y)
            y *= u;
        else 
            z *= u;    
    }
    if (x == 1 || y == 1 || z == 1) {
        cout << "NO\n";
        return;
    }
    if (x == y || y == z || x == z) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
