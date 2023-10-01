/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 19:57:31
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

int n;
vector <int> a;
string s = "";

bool ok(){
	for (int i = n; i >= 1; --i)
		if (a[i] != n) return true;
	return false;
}

void rcombi(){
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) a[i] = 1;

	while (ok()){
		cout << s;
		for (int i = 1; i <= n; i++) cout << a[i];
		cout << '\n';
	
		int i = n;
		while (i >= 1 && a[i] == n) --i;
		a[i]++;
		for (int j = i + 1; j <= n; j++) a[j] = 1; 
	}
	cout << s;
	for (int i = 1; i <= n; i++) cout << a[i];
	cout << '\n';
}

void decode(){
	for (int i = 0; i <= n - 1; ++i)
		s += (char)('A' + i);
	do {
		
		rcombi();

	}while (next_permutation(all(s)));
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	decode();
		 
}
