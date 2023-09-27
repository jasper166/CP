#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int w[], int v[], int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i <= n; ++i){
        for (int j = W; j >= 0; j--){
            if (!i || !j) continue;
            if (j >= w[i - 1])
                dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}
int main()
{
    int v[] = { 22, 19, 12, 15, 21, 12, 16, 11  };
    int w[] = { 3, 5, 1, 3, 4, 4, 2, 1 };
    int W = 5;
    int n = sizeof(v) / sizeof(v[0]);
    // int n, W;
    // cin >> n >> W;
    // int w[n + 1], v[n + 1];
    // for (int i = 1; i <= n; ++i) cin >> w[i];
    // for (int i = 1; i <= n; ++i) cin >> v[i];
    cout << knapSack(W, w, v, n);
    return 0;
}