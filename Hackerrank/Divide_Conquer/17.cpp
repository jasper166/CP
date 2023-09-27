/**    
* LANG: C++ 
* author: atom 
* created: 09.06.2022 06:54:52
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

ll merge(int a[], int l, int r, int m){

    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    ll ans = 0;
    while (i < (int) x.size() && j < (int) y.size()){
        if (x[i] <= y[j])
            a[l++] = x[i++];
        else {
        	ans += x.size() - i;
        	a[l++] = y[j++];
        } 
    }
    while (i < (int) x.size()) a[l++] = x[i++];
    while (j < (int) y.size()) a[l++] = y[j++];
    return ans;
}

ll mergeSort(int a[], int l, int r){
    ll ans = 0
    if (l < r){
        int m = (l + r) / 2;
        ans += mergeSort(a, l, m);
	    ans += mergeSort(a, m + 1, r);
        ans += merge(a, l, r, m);
    }
    else return ans; 
}



int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int a[n];
	for (int &i : a) cin >> i;
	cout << cInver(a, 0, n - 1) << '\n'; 
	


}
