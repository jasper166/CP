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
    
    ifstream data("bad");
    int n;
    vector <int> bad;
    while (data >> n) {
    	bad.push_back(n);
    }
    debug(bad);
    ifstream data2("good");
    vector <int> good;
    while (data2 >> n) {
    	good.push_back(n);
    }
    debug(good);
    for (int i = 0; i < (int) bad.size(); ++i) {
    	if (bad[i] != good[i]) {
    		cout << i << "\n";
    		break;
    	}
    }
}

