/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 16:27:02
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

string s;
int n;

void next_permu(){

	int i = n - 2;
	string res;
	while (i >= 0 && s[i] >= s[i + 1]) --i;
	if (i == -1) 
		res = "NOT EXIST";
	else {
		int j = n - 1;
		while (j >= 0 && s[j] <= s[i]) --j;
		swap(s[j], s[i]);
		sort(s.begin() + i + 1, s.end());
		res = s;
	}
	cout << res << '\n';
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s;
	n = s.size();

	next_permu();
		 
}
