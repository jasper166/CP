#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) (a > b)? a : b;
#define min(a,b) (a < b)? a : b;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define cin(a) scanf("%d", &a);
#define cout(a) printf("%d ", a);
#define endl printf("\n");
typedef long long ll;
typedef unsigned long long ull;

typedef struct word{
	char c[20];
	int f;
}word;

int find(char *x, word a[], int n){
	FOR(i, 0, n-1){
		if(strncmp(a[i].c, x,strlen(a[i].c)) == 0) return i;
	}
	return -1;
}

void solve(){
	char s[102];
	word a[20];
	fgets(s, 102, stdin);
	char *tok = strtok(s, " ");
	int n = 0;
	while(tok != NULL){
		if(find(tok, a, n) != -1){
			int j = find(tok, a, n);
			a[j].f++;
		}
		else{
			strcpy(a[n].c, tok);
			a[n++].f++;
		}
		
		tok = strtok(NULL, " ");
	}
	FOR(i, 0, n-1){
		printf("%s ", a[i].c);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		// int n; cin(n);
		// solve(n);
		solve();
	return 0;
}