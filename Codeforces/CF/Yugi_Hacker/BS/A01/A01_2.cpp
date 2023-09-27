/**    
* LANG: C++ 
* author: atom 
* created: 18.05.2022 14:01:14
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

int n, q;
vector <int> a;

int one(int x){
	auto it = lower_bound(all(a), x);
	return (it != a.end())? *it : -1;
		
}

int two(int x){
	auto it = upper_bound(all(a), x);
	return (it != a.end())? *it : -1;
		
}

int three(int x){
	int j = upper_bound(all(a), x) - a.begin();
	return (j != 0)? a[j - 1] : -1;
}

int four(int x){
	int i = lower_bound(all(a), x) - a.begin();
	return (i != 0)? a[i - 1] : -1;
}		

int five(int x){
	int i = lower_bound(all(a), x) - a.begin();
	int j = upper_bound(all(a), x) - a.begin() - 1;
	//cout << i << j << '\n';
	return (a[i] == x && a[j] == x)? j - i + 1 : -1; 
}		


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	a.resize(n);
	for (int &i : a) cin >> i;
	while (q--){
		int t, x;
		cin >> t >> x;
		switch(t){
			case 1:
				cout << one(x) << '\n';
				break;
			case 2:
				cout << two(x) << '\n';
				break;
			case 3:
				cout << three(x) << '\n';
				break;
			case 4:
				cout << four(x) << '\n';
				break;
			default:
				cout << five(x) << '\n';
				break;
		}
	}
		 
}
