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

int k;
string s;


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> k >> s;
	priority_queue <int> pq;
	map<char, int> freq;
	ll ans = 0;
	if (k <= s.length()){
	for (char c : s){
		freq[c]++;
	}
	for (auto it : freq){
		pq.push(it.S);
	}

	while (k){
		int i = pq.top();
		i--;
		k--;
		pq.pop();
		pq.push(i);
	}
	while (!pq.empty()){
		ans += 1LL * pq.top() * pq.top();
		pq.pop();
	}
}
	cout << ans << '\n';
}	
