#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n';

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    if (n == 1) {
        if (a[0] == 0)
            cout << "YES" << el;
        else cout << "NO" << el;
        return;
    } 
    if (a.back() > 0 || a[0] < 0) {
        cout << "NO" << el;
        return;
    }
    
    bool ok = true;
    vector<int> b(n, 1);
    b[n - 1] = 0;
    int pos = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != 0) break;
        b[i] = 0;
        if (i - 1 >= 0) b[i - 1] = 0;
        pos = i - 1;
    }
    
    if (a[pos] > 0) {
        cout << "NO" << el;
        return;
    }
    
    bool c = true;
    for (int i = pos - 1; i >= 0; --i) {
        if (c) b[i] = abs(a[i + 1]) - 1;
        else b[i] += abs(a[i + 1] - b[i + 1]) - (i > 0 ? 1 : 0);
        if (a[i] > b[i]) {
            cout << "NO" << el;
            return;
        }
        c = false;
    }
    
    cout << "YES" << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}