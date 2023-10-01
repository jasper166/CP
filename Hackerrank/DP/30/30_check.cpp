#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void fast_io()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);    
} 
int dp[1000][1000];
int main()
{
     
    fast_io();
    int n, m, Max, Min; cin >> n >> m;
    for(int i = 1; i <= m; i++) dp[1][i] = i-1;
    for(int i = 1; i <= n; i++) dp[i][1] = i-1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 2; j <= m; j++)
        {
            Max = max(i,j); Min = min(i,j);
            if(Max % Min == 0)
            {
                dp[i][j] = Max / Min - 1;
                continue;
            }
            dp[i][j] = Max / Min;
            dp[i][j] += dp[Max - dp[i][j]*Min][Min];
        }
    }
    cout << dp[n][m] << '\n';
}