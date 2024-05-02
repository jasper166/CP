/*	
	TASK: SHELL
  	LANG: C++
  	author: TRAN MINH HIEU
	Handle: at0miccat
  	
 */
#include "bits/stdc++.h"

using namespace std;

int p[10];
ifstream fin ("shell.in");
ofstream fout ("shell.out");

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	int n;
	fin >> n;
	int pebble[4], cnt[4] = {0};
	for (int i = 0; i <= 3; i++) pebble[i] = i;
	while (n--){
		int a, b, g;
		fin >> a >> b >> g;
		swap(pebble[a], pebble[b]);
		cnt[pebble[g]]++;
	}

	fout << *max_element(cnt, cnt + 4) << "\n";
	return 0;
}
