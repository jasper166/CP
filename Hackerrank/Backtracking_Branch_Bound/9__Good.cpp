#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


void FileIO(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);
}

int s,n,t[100],a[100],k,ok,res;

bool check(){
	int sum=0;
	for(int i=1;i<=k;i++){
		sum+=t[a[i]];
	}
	return sum==s;
}

void next(){
	int i=k;
	while(i>=1 && a[i]==n-k+i){
		--i;
	}
	if(i==0) ok=false;
	else{
		a[i]++;
		for(int j=i+1;j<=k;j++) a[j]=a[j-1]+1;
	}
}

void inp(){
	cin>>n>>s;
	FOR(i,1,n+1) cin>>t[i];
	sort(t+1,t+n+1,greater<int>());
	res=0;
	for(int i=1;i<=n;i++){
		k=i;
		ok=1;
		for(int j=1;j<=k;j++) a[j]=j;
		while(ok){
			if(check()){
				cout<<i<<"\n";
				return;
			}
			next();
		}
	}
	cout<<"-1\n";
}

int main(){
	// int t;cin>>t;
	int t = 1;
	while(t--){
		inp();
	}
}
