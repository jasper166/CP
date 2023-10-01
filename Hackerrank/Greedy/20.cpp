/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 07:02:17
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

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int a[n];
	vector <int> odd, even;
	for (int &i : a){
		cin >> i;
		if (i & 1) odd.pb(i);
		else even.pb(i);
	}
	bool flag = 0;
	if (((even.size() == odd.size() && even.size() == 1)) ||
		((even.size() % 2 == 0) && (odd.size() % 2 == 0)))
		flag = 1;
	else {
		sort(all(odd));
		sort(all(even));
		int i = 0, j = 0, k = 0;
		while (i < even.size() && j < odd.size()){
			if (abs(even[i] - odd[j]) == 1){
				k++;
				break;
			}
			else if (even[i] > odd[j]) j++;
			else i++;
		}
		flag = (k == 1);
	}
	cout << (flag? "YES" : "NO") << '\n';
}
