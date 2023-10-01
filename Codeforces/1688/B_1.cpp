/**    
* LANG: C++ 
* author: atom 
* created: 03.06.2022 20:00:36
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

int n, t, ok = 1;


void bt(int j, int cur){
	vector <int> ans;
	vector <vector<int>> res;
	int a[100];
	if (cur == 0){
		res.pb(ans);
		ok = 1;
		return;
	}
 
	while (j <= n && cur - a[j] >= 0){
		ans.pb(a[j]);
		bt(j, cur - a[j]);
		j++;
		ans.pop_back();
	}
 
}


int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
    	int a[n];
    	bool flag = 0;
    	for (int &i : a) cin >> i;
    	int diff = 0, total = MOD;

    	auto findDiff = [&] (int m) {
   			int ans = 0;
    		for (; m; m /= 2, ans++)
       	 	 	if(m & 1) break;
  	  		return ans;
		};


    	for (int i : a) {
       		if(!(i & 1)){
        		total = min(total, findDiff(i));
            	diff++;
        	} 
        	else flag = true;
    	}
    	int ans = (flag? diff : total + diff - 1);
    	cout << ans << '\n';
	}
		 
}
