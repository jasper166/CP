/*	
 * 	author: Hiu 
 *  Handle: at0miccat
 */
#include "bits/stdc++.h"
 
using namespace std;
 
bool cmp (pair<int, int> a, pair<int, int> b){
	return a.second > b.second;
}
 
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int arr[n];
 
	for (int &i : arr){
		cin >> i;
	}
	sort(arr, arr + n);
	int med = (n - 1)/2;
	long long ans = 0;
	for (int i : arr){
		ans += (long long) abs(arr[med] - i);
	}
	cout << ans;
	return 0;
}
