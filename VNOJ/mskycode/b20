#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// B20
const int MAX = 1e2 + 5;

int n;
int a[MAX];

void run_case() {
    cin >> n;

    vector <int> odd, even;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x & 1)
            odd.push_back(x);
        else
            even.push_back(x);
    }

    int O = odd.size();
    int E = even.size();
    if (O % 2 == 0 && E % 2 == 0) {
        cout << "YES\n";
        return;
    } 

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    
    // tim dc 1 cap abs(x, y): x thuoc Odd hoac even, y thuoc tk con lai
    int i = 0, j = 0;
    int cnt = 0;
    while (i < E && j < O) {
        if (abs(even[i] - odd[j]) == 1) {
            cnt++;
            break;
        }
        else if (even[i] > odd[j]) 
            j++;
        else 
            i++;
    }
    cout << (cnt? "YES\n" : "NO\n");
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
