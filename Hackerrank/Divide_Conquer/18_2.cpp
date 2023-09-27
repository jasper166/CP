/**    
* LANG: C++ 
* author: atom 
* created: {command:date +"%d.%m.%Y %H:%M:%S"}
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif



vector<ll>t(51,0);
ll sl=0;
void push01(ll n)
{
    t.clear();
    t.resize(51,0);
    t[1]=2;
    n=n>>1;
    int i=2;
    while(n>0)
    {
        t[i]=t[i-1]*2;
        i++;
        n=n>>1;
    }
    sl=i-1;
    debug(t);
    debug(sl);
}
int tim(ll pos,ll n,ll k)
{
    if (pos == 1) return n%2;
    ll tmp=t[pos-1];
    if(k==tmp) return n%2;
    if(k<tmp) return tim(pos-1,n/2,k);
    return tim(pos-1,n/2,k-tmp-1);
}



int orz(){
    cin.tie(nullptr) -> sync_with_stdio(false);

    ll l , n , r, res = 0;
    cin>>n>>l>>r;
        push01(n);
        for(ll i=l;i<=r;i++) res+=tim(sl,n,i);
        cout<<res<<'\n';
    return 0;

         
}