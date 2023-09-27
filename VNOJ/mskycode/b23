#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// B23
const int MAX = 1e2 + 5;

string s;
int n;
void run_case() {
    cin >> s;
    n = s.size();

    priority_queue <int> q;
    for (int i = 0; i < n; i++) {
        int len = (s[i] == '1')? 0 : -1;
        while (i < n && s[i] == '1') {
            len++;
            i++;
        }
        if (len != -1)
            q.push(len);
    }

    vector <int> turn;
    while (!q.empty()) {
        turn.push_back(q.top());
        q.pop();
    }
    int ans = 0;
    for (int i = 0; i < turn.size(); i += 2) {
        ans += turn[i];
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
