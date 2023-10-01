/*	
 * 	author: Hiu 
 *  Handle: at0miccat
 *	manh cute pho mai we :>
 */
#include "bits/stdc++.h"
 
using namespace std;
 
// first pos of ele that < x - a;
int pos(int a[], int l, int r, int x){
	int pos = -1;
	while(l <= r){
		int m = (l + r)/2;
		if(a[m] <= x){
			pos = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return pos;
}
 
 
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	
	int n, x;
	cin >>  n >> x;
	int kids[n];
	for(int &i : kids) cin >> i;
	int free = 0;
	sort(kids, kids + n);
	for(int i = 0; i <= n - 1; i++){
		int j = pos(kids, i + 1, n - 1, x - kids[i]);
		if(j != - 1){
			free++;
			kids[j] = x;
		}
	}
	cout << n - free;
	return 0;
}
