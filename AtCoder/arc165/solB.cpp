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
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int n, k;
    cin >> n >> k;
    vector <int> a(n + 5);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // because of sorting, if there exist a sorted-windows -> the largest permutation is array its own
    // if none window exists, only the last window affects our answer as first n - k elements remain unchanged
   	// or find smallest i with x = n - k such min_a(x + 1, i + k - 1) >= a[x];
    // i ... x... i + k - 1 and a(i) < a(i + 1) <...
    int p = 1;	
	vector <int> prf(n + 5);
    for (int i = 2; i <= n; ++i) {
    	if (a[i] > a[i - 1]) p++;
    	else p = 1;
    	if (p >= k) {
    		for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
    		return 0;
    	}
    }

    // RMQ for min
   	vector <int> lg(n + 5);
   	lg[1] = 0;
   	for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;

   	int b = 0;
   	while ((1 << b) <= n) ++b;
   	vector <vector <int>> rmq(b, vector <int> (n + 5, 1e9));
   	for (int i = 1; i <= n; ++i)
   		rmq[0][i] = a[i];

   	for (int x = 1; x < b; ++x) {
   		int st = 1 << (x - 1);
   		for (int i = 1; i + st <= n; ++i) 
   			rmq[x][i] = min(rmq[x - 1][i], rmq[x - 1][i + st]);
   	}

   	auto qry = [&] (int l, int r) -> int {
   		if (l > r) return 1e9;
   		int x = lg[r - l + 1];
   		return min(rmq[x][l], rmq[x][r - (1 << x) + 1]);
   	};
   	// RMQ end

   	int j = n - k + 1;
   	int x = j;
   	bool inc = a[j] > a[j - 1]; 
   	for (int i = n - k; i >= 1; --i) {
   		if (inc && (x + 1 <= i + k) && qry(x + 1, i + k) > a[i]) j = i;
   		inc &= (a[i] > a[i - 1]);	
   	}
   	// debug(j);
   	sort(a.begin() + j, a.begin() + j + k);
   	for (int i = 1; i <= n; ++i)
   		cout << a[i] << " \n"[i == n];

   	return 0;
}

