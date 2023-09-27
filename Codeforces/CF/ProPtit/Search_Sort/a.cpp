#include <stdio.h>

long long map[102][102];

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		long long a[n + 1][n + 1];
		for (int i = 0; i <= n - 1; i++)
			for (int j = 0; j <= n - 1; j++) scanf("%lld", a[i][j]);


		int m = 0;
		for (int j = 0; j <= n - 1; ++j)
			for (int i = 0; i <= n - 2; ++i){
				long long cur = a[i][j];
				int cnt = 1;
				for (int k = i + 1; k <= n - 1; k++)
					if (a[k][j] == cur) cnt++;
				if (cnt == 2) map[i][j] = cur;
			}
		for (int i = 0; i < m; i++)
			if (map[])
	}

}