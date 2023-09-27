/*	
	TASK: 
  	LANG: C++
  	author: TRAN MINH HIEU
	Handle: at0miccat
  	
 */
#include "bits/stdc++.h"
#define F first
#define S second

using namespace std;

	ifstream fin ("shuffle.in");
	ofstream fout ("shuffle.out");

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	int n;
	fin >> n;
	vector <int> a(n), s(n);
	for (int &i : s) fin >> i;
	for (int &i : a) fin >> i;	
	int t = 3;
	while (t--){
		vector <int> b;
		b = a;	
		for (int i = 0; i <= n - 1; i++) 
			a[i] = b[s[i] - 1];
	}
	for (int i : a) fout << i << "\n";
	return 0;
}
