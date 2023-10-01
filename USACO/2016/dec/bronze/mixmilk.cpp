/*	
	TASK: milk2
  	LANG: C++
  	author: TRAN MINH HIEU
	Handle: at0miccat
  	manh cute pho mai we :3
  	
 */
#include "bits/stdc++.h"

using namespace std;

struct milk{
	int c;
	int m;
};

void cycle(milk b[]){
	for (int j = 1; j <= 100; j++){
		int i = j % 3;
		i--;
		int k = i + 1;
		if (j % 3 == 0) i += 3;
		if (b[i].m <= b[k].c - b[k].m){
			b[k].m += b[i].m;
			b[i].m = 0;
		}
		else{
			b[i].m -= b[k].c - b[k].m;
			b[k].m = b[k].c;
		}
	}
}

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	ifstream fin ("mixmilk.in");
	ofstream fout ("mixmilk.out");

	milk b[3];
	for (int i = 0; i <= 2; i++) fin >> b[i].c >> b[i].m;
	cycle(b);
	for (auto i : b) fout << i.m << "\n";
	return 0;
}
