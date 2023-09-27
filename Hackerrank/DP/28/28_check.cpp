#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
void fast_io()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);    
} 
int a[100005], dp[100005][105];
int main()
{ 
    fast_io();
    int n, m, id = 0; cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(!a[i]&& !id) id = i;
    }
    if(id == 1) for(int i = 1; i <= m; i++) dp[id][i] = 1;
    else for(int i = a[id-1] - 1; i <= min(a[id-1] + 1, m); i++) dp[id][i] = 1;
    for(int i = id + 1; i <= n; i++)
    {
        if(a[i])
        {
            dp[i][a[i]] = dp[i-1][a[i]-1] + dp[i-1][a[i]] + dp[i-1][a[i] + 1];
            dp[i][a[i]] %= MOD;
        }
        else
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
    }
    if(a[n]) cout << dp[n][a[n]] << '\n';
    else
    {
        ll sum = 0;
        for(int i = 1; i <= m; i++)
        {
            sum += dp[n][i];
            sum %= MOD;
        }
        cout << sum << '\n';
    }
}