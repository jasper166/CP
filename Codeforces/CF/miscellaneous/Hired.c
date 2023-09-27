#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define min(a, b) (a < b)? a : b
#define max(a, b) (a > b)? a : b
#define ll long long
const int MAX = 1e4 + 2;

int cnt [502], k;

void solve(char *a){
	memset(cnt, 0, sizeof(int));

	for (int i = 0; i <= (int) strlen(a) - 1; ++i){
		if (a[i] >= 'A' && a[i] <= 'Z') a[i] = (char) a[i] + ('a' - 'A');
	}
	for (int i = 0; i <= (int) strlen(a) - 1; ++i){
		cnt[a[i]]++;
	}
	int f = 0;
	for (int i = 'a'; i <= 'z'; ++i){
		if (cnt[i]) f++;
	}
	printf("%d\n", (k >= 26 - f));
}

int main(){
  int t;
  scanf("%d\n", &t);
  while(t--){
  	char a[1000002];
  	scanf("%s", a);
  	scanf("%d", &k);
  	solve(a);
  	// puts(a);
  }
  return 0;
}