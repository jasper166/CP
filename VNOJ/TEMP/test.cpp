#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll dx[8]={ -1, -1, 0, 1, 1, 1, 0, -1}, dy[8]={ 0 , 1 , 1 , 1, 0 , -1 , -1 ,-1};
char a[100][100];
ll DP[100][100],check[100][100];
void nhap(){
	cin >> n;
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++) cin >> a[i][j];
	}
	for(ll i = 0;i <= n;i++){
		for(ll j = 0 ;j <= n;j++)DP[i][j]=0;
	}
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=n;j++)check[i][j]=0;
	}
	
}
void loang(ll i,ll j){
	a[i][j] = 'Z';
	for(ll k = 0;k < 8;k++ ){
		ll I = i + dx[k], J = j + dy[k];
		if(I >= 1 && I <= n && J >= 1 && J <= n && a[I][J] == 'O')loang(I,J);
	}
}
void solve(){
	nhap();
	for(ll j = 1;j <= n;j++){
		if( a[1][j] == 'O')loang(1,j);
	}
	for(ll j = 1;j <= n;j++){
		if( a[n][j] == 'O')loang(n,j);
	}
	for(ll i = 1;i <= n;i++){
		if( a[i][1] == 'O')loang(i,1);
	}
	for(ll i = 1;i <= n;i++){
		if( a[i][n] == 'O')loang(i,n);
	}
//
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			if(a[i][j] == 'O' || a[i][j] == 'X'){
				DP[i][j]=min( { DP[i-1][j] , DP[i-1][j-1] , DP[i][j-1] } )+1;
				if(a[i][j]=='O' || check[i-1][j] || check[i-1][j-1] || check[i][j-1])check[i][j]=1;
			}
			else {
				DP[i][j] = 0;
				check[i][j]=0;
			}
		}
	}
	ll ans = 0;
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			if(check[i][j])ans=max(ans,DP[i][j]);
		}
	}
	cout << ans << endl;
}
int main(){
	int t; cin>> t;
	while(t--){
		solve();
	}
}
