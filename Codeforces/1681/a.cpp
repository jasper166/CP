/**    
* LANG: C++ 
* author: atom 
* created: 23.05.2022 21:25:36
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int t, n, m;

void fi(int *a, int *b){
	int m1 = *max_element(a, a + n);
	int m2 = *max_element(b, b + m);
	if (m1 >= m2) cout << "Alice" << '\n';
	else cout << "Bob" << '\n';
}


void se(int *a, int *b){
	int m1 = *max_element(a, a + n);
	int m2 = *max_element(b, b + m);

	if (m1 > m2) cout << "Alice" << '\n';
	else cout << "Bob" << '\n';
}



int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		cin >> n;
		int a[n];
		for (int &i : a) cin >> i;
		cin >> m;
		int b[m];
		for (int &i : b) cin >> i;

		fi(a, b);
		se(a, b);

	}
		 
}
