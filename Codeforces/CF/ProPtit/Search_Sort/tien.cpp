#include <stdio.h>
#include <stdbool.h>

int n, idx = 0;
bool check(int arr[][102], int gan){
	for(int i = 0; i < n; i++){
		int dem = 0;
		for(int j = 0; j < n; j++){
			if(arr[j][i] == gan) dem++;
		}
		if(dem != 2) return 0; 
	}
	return 1;
}
int main(){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int arr[n + 1][102];
		for (int i = 0; i <= n - 1; i++)
			for (int j = 0; j <= n - 1; j++) scanf("%d", &arr[i][j]);
		int dd[105] = {};
		for(int i = 0; i < n; i++)
		{
			int gan = arr[i][0];
			int dem = 0;
			for(int j = 0 ; j < n; j++)
			{
				if(arr[j][0] == gan) dem++;
			}
			if(dem == 2)
			{
				int chec = 0;
				for(int i = 0; i < idx; i++) {
					if(dd[i] == gan) chec = 1;
				}
				if(chec == 0) dd[idx++] = gan;
			}
		}
		int flag = 0;
		for(int i = 0; i < idx; i++)
			if(check(arr, dd[i])) {
				flag = 1;
				printf("%d ", dd[i]);
		}	
		if (!flag) printf("-1\n");
	}
}