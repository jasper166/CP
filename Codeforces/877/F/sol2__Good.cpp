#include<bits/stdc++.h>

#define faster() cin.tie(0)->sync_with_stdio(0)
#define clean() cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define ld long double
#define ll long long 
#define lli unsigned long long int
#define For(i,a,b) for(ll i=a;i<b;i++)
#define Forr(i,a,b) for(ll i=a;i>=b;i--)
#define sortu(a) sort(a.begin(),a.end())
#define sortv(a) sort(a.rbegin(),a.rend())
#define pip pair<int,int> 
#define pause() system("pause");

using namespace std;
ll gcd(ll a,ll b,int& x,int& y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    int x1,y1;
    ll d = gcd(b,b%a,x1,y1);
    x = y1;
    y = x1-y1*(a/b);
    return d;
}
ll inv(ll a,ll m){
    int x,y;
    ll d = gcd(a,m,x,y);
    if(d!=1) return 0;
    return (x%m+m)%m;
}
void solve(){
    int a;cin>>a;
    cout << inv(a,mod);
}
int main(){
    faster();
    solve();
}