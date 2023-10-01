#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// B24
const int MAX = 1e2 + 5;

string s;
int n;
void run_case() {
    cin >> s;
    int cnt = 0;
    map <char, int> mp;
    for (auto x : s)
        mp[x]++;
    for (auto [x, c] : mp)
        if (c & 1)
            cnt++;
    if (cnt == 0) {
        cout << "1\n";
        return;
    }
    cout << ((cnt & 1)? 1 : 2) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
