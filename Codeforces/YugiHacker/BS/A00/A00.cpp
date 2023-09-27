	/**    
	 *  @Author: Hiu 
	 *  @Handle: at0miccat
	**/
	#include "bits/stdc++.h"
	using namespace std;
	using ll = long long;

	#define orz main
	#define fi first
	#define se second
	#define pii pair <int, int>
	#define pb push_back
	#define all(x) x.begin(), x.end()

	constexpr int MOD = 1e9 + 7;
	constexpr int MAX = 1e6 + 2;

	// #ifdef LOCAL
	// #include "myLib.h"
	// #else
	// #define debug(...) 42
	// #endif

	int first_pos(int x, int a[], int n){
		int l = 0, r = n - 1;
		int res = -1;
		while (l <= r){
			int m = (l + r) / 2;
			if (a[m] >= x){
				if (a[m] == x) res = m + 1;
				r = m - 1;
			}
			else l = m + 1;
			
		}
		return res;
	}

	int last_pos(int x, int a[], int n){
		int l = 0, r = n - 1;
		int res = -1;
		while (l <= r){
			int m = (l + r) / 2;
			if (a[m] <= x) {
				if (a[m] == x) res = m + 1;
				l = m + 1;
			}
			else r = m - 1;
			
		}
		return res;
	}

	int orz(){
		ios_base:: sync_with_stdio(false);
		cin.tie(nullptr);

		int n, q;
		cin >> n >> q;
		int a[n];
		for (int &i : a) cin >> i;
		while (q--){
			int t, x;	
			cin >> t >> x;
			if (t == 1){
				if (binary_search(a, a + n, x)) 
					cout << "YES\n";
				else 
					cout << "-1\n";
			}
			else if (t == 2)
				cout << first_pos(x, a, n) << "\n";
			else 
				cout << last_pos(x, a, n) << "\n";
		 }
	}
