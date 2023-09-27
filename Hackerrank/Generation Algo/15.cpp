/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 15:46:03
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
string s;
vector <int> a;

bool ok(){
	for (int i = n - 1; i >= 1; i--)
		if (a[i] < a[i + 1]) return true;
	return false;
}

void permu(){
	sort(all(s));
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) a[i] = i;

	int i = n;
	while (ok()){
		for (int i = 1; i <= n; i++) cout << s[a[i] - 1];
		cout << '\n';

		int i = n - 1;
		while (i >= 1 && a[i] > a[i + 1]) --i;
		int j = n;
		while (j >= 1 && a[j] < a[i]) --j;
		swap(a[i], a[j]);
		sort(a.begin() + i + 1, a.end());

	}
	for (int i = 1; i <= n; i++) cout << s[a[i] - 1];
		cout << '\n';

}

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	set <char> se;
	string t = "";
	for (char c : s) se.insert(c);
	for (char c : se) t += c; 
	s = t;
	n = s.size();
	permu();
		 
}
