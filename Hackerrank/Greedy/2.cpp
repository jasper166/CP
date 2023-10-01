/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 01:21:11
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

string a, b;

ll _minSum(){
	string x = a, y = b;
	for (char &c : x)
		if (c == '6') c--;
	for (char &c : y)
		if (c == '6') c--;
	return stoll(x) + stoll(y);
}

ll _maxSum(){
	string x = a, y = b;
	for (char &c : x){
		if (c == '5') c++; 
	}
	for (char &c : y)
		if (c == '5') c++;
	return stoll(x) + stoll(y);
}



int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	cout << _minSum() << ' ' << _maxSum() << '\n';
			 
}
