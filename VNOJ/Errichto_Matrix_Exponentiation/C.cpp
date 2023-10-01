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
#define endl printf("\n")
typedef long long ll;
typedef unsigned long long ull;


bool cmp(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}
// void assert(){
// 	char s[] = "Hello World";
// 	char a[1000];
// 	strlen(s);
// 	strcpy(a, s);
// 	strcmp(a, s);
// 	strcat(a, s);
// 	// strlwr(a);
// 	// strupr(a);
// 	// strrev(a);
// 	strstr(a, "Hello");
// 	strchr(a, 'H');

// 	int b[] = {1, 2, 3, 4, 5, 6};
// 	qSort(b, sizeof(b / sizeof(b[0])), sizeof(int), cmp);
	
// 	FILE *f1;
// 	FILE *f2;
// 	f1 = fopen("Hello.txt", "r");
// 	f2 = fopen("Answer.txt", "w");
// 	int j;
// 	fscanf(f1, "%d", &j1);
// 	fprintf(f2, "%d", j1);
// 	fclose(f1);
// 	fclose(f2);
// }

int t;
int sCMP(char *a, char *b){
	int n = strlen(a), m = strlen(b);
	if (n > m) return 1;
	else if (n < m) return -1;
	else {
		for (int i = 0; i <= n - 1; i++){
			if (a[i] < b[i]) return -1;
			else if (a[i] > b[i]) return 1;
		}
		return 0;
	}
}

void Subtract(char *a, char *b){
	char x[1002] = {'\0'};
	char y[1002] = {'\0'};
	// x >= y;
	if (sCMP(a, b) >= 0) strcpy(x, a);
	else strcpy(x, b);
	if (sCMP(a, b) >= 0) strcpy(y, b);
	else strcpy(y, a); 

	int x1[1002] = {0};
	int y1[1002] = {0};
	int ans[1002] = {0};
	int n = strlen(x) - 1, m = strlen(y) - 1;

	// for (int i = 0; i <= n; i++) printf("%c", x[i]);
	// printf("\n");

	// for (int i = 0; i <= m; i++) printf("%c", y[i]);
	// printf("\n");

	for (int i = 1001, h = n; i >= 0 && h >= 0; --i, --h)
		x1[i] = (x[h] - '0');
	for (int i = 1001, k = m; i >= 0 && k >= 0; --i, --k) 
		y1[i] = (y[k] - '0');
	int borrow = 0;


	// for (int i = 1001 - n; i <= 1001; i++) printf("%d", x1[i]);
	// printf("\n");

	// for (int i = 1001 - n; i <= 1001; i++) printf("%d", y1[i]);
	// printf("\n");
	
	for (int i = 1001; i >= n; i--){
		int diff = x1[i] - y1[i] - borrow;
		if (diff < 0){
			borrow = 1;
			diff += 10;
		}
		else borrow = 0;
		ans[i] = diff;
	}
	int pos = 0;
	while (ans[pos] == 0) pos++;
	// printf("%d\n", pos);
	if (pos == 1002) printf("0");
	else {
		for (int i = pos; i <= 1001; i++)
			printf("%d", ans[i]);
	}
	printf("\n");
}


int main(){

	scanf("%d", &t);
	while (t--){
		char a[1002], b[1002];
		scanf("%s%s", a, b);
		Subtract(a, b);
	}


	return 0;
}