#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#ifdef LOCAL
#include "debug.h"
#define TASK "OLP61"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif
#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 20;
//
const int N=1e6;
int n,x,last;
int a[25][25];
int dp[N][16];
bool check[N][16];
void reset(){
    last=(1<<n)-1;
    for(int i=1;i<=last;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=INT_MAX;
            check[i][j]=0;
        }
    }
}
void solve(){
    reset();
    queue<ii>q;
    q.push({0,0});
    check[0][0]=1;
    dp[0][0]=0;
    while(!q.empty()){
        ii u=q.front(); q.pop();
        for(int i=1;i<=n;i++){
            int k=1<<(i-1);
            if((u.fi&k)==0){
                x=u.fi^(1<<(i-1));
                dp[x][i]=min(dp[x][i],dp[u.fi][u.se]+a[u.se][i]);
                if(check[x][i]==0){
                    check[x][i]=1;
                    q.push({x,i});
                }
            }
        }
    }
    int ans =*min_element(dp[last]+1,dp[last]+n+1);
    cout<<ans<<endl;
}
//
signed main(){
    cin.tie(0) -> sync_with_stdio(0);;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)cin>>a[i][j];
        }
        solve();
    }
    return 0;
}