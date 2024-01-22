#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    ifstream data("outWrong");
    int n, m;
    vector <pair <int, int>> bad;
    while (data >> n >> m) {
    	bad.push_back({n, m});
    }
    // debug(bad);
    ifstream data2("outSlow");
    vector <pair <int, int>> good;
    while (data2 >> n >> m) {
    	good.push_back({n, m});
    }
    // debug(good);
    for (int i = 0; i < (int) bad.size(); ++i) {
    	if (bad[i] != good[i]) {
    		cout << i + 1 << "\n";
    		break;
    	}
    }
}

