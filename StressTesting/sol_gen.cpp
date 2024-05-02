#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rd(l, r) uniform_int_distribution <int> (l, r) (rnd)
#define rdll(l, r) uniform_int_distribution <ll> (l, r) (rnd)

const int T = 10;
const string F = "sol";

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        // freopen("in1", "r", stdin);
    #endif

    for (int t = 1; t <= T; ++t) {
    	fstream fout((F + ".in"));
    	// thong tin input
    	int n = rd(1, 10);
    	vector <int> p(n);
    	iota(p.begin(), p.end(), 1);
    	// p = 1, 2, 3,.. n

    	shuffle(p.begin(), p.end(), rnd);

    	fout << n << "\n";
    	for (int x : p) fout << x << " ";
    	fout << "\n";

    	///
    	fout.close();

    	system((F + ".exe").c_str()); // chay file sol
    	system((F + "_good.exe").c_str()); // chay file sol_good

    	// fc sol.out sol.out_good
    	if (system(("fc " + F + ".out " + F + ".out_good").c_str()) != 0) {
    		// test sai 
    		cout << "Test: " << t << " - WRONG ANSWER!\n";
    		exit(0);
    	}
    	else 
    		cout << "Test: " << t << " - CORRECT ANSWER!\n";
    }
    
    return 0;
}
