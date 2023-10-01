#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// B19
const int MAX = 1e4 + 5;

int open, close;
// open = close;

string s;
int n;
void run_case() {
    cin >> s;
    n = s.size();
    s = "$" + s;
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += (s[i] == '(')? 1 : -1;
        if (cnt < 0)
            cnt++;
    }
    cout << cnt << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
