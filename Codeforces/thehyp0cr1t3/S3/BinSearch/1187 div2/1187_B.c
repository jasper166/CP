/**    
* LANG: C 
* author: atom 
* created: 10.06.2022 23:52:30
**/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) (a > b)? a : b;
#define min(a,b) (a < b)? a : b;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define cin(a) scanf("%d", &a)
#define cout(a) printf("%d ", a)
#define el printf("\n")
typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;
const int MAX = 1e5;

char s[200002];
char x[200002];
int n, m;
int cnt[200002][26] = {0};

bool ok(int mid){
	int cnt2[26] = {0};
	int l = strlen(x);
	FOR(i, 0, l - 1) cnt2[x[i] - 'a']++;
	for (int c = 0; c <= 25; c++){
		if (cnt[mid - 1][c] < cnt2[c]) return false;
	}
	return true;
}



int main(){

	scanf("%d%s%d", &n, s, &m);


	FOR(i, 0, n - 1){
		cnt[i][s[i] - 'a']++;
		if (i){
			for (int c = 0; c <= 25;  c++)
				cnt[i][c] += cnt[i - 1][c];
		}
	}

	while (m--){
		scanf("%s", x);
		int l = 1, r = n, ans = n;
		while (l <= r){
			int mid = (l + r) >> 1;
			if (ok(mid)){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		printf("%d\n", ans);

	}


}