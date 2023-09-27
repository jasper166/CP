/*	
	TASK: Sleepy
  	LANG: C++
  	author: TRAN MINH HIEU
	Handle: at0miccat
  	
 */
#include "bits/stdc++.h"

using namespace std;

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	ifstream fin ("sleepy.in");
	ofstream fout ("sleepy.out");
	int n;
	fin >> n;
	int a[n];
	for (int &i : a) fin >> i;
	int cnt = 0;
	for (int i = n - 1; i >= 1; i--){
		if (a[i] > a[i - 1]) cnt++;
		else break;
	}
	fout << n - cnt - 1 << "\n";
	return 0;
}
