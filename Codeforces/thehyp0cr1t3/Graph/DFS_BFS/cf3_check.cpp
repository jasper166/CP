#include<bits/stdc++.h>
using namespace std;

#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 200005
int n, a[maxn], ans=1e9, f[maxn], s[maxn];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    f1 (i, n) cin >> a[i], s[i]=s[i-1]+a[i];
    int s1=a[n]+a[n-1], s2=0;
    int p=n+1;
    for (int i=n-2; i; i--)
    {
        while (p-1>i && s1-a[p-1] >= s2+a[p-1]) p--, s1-=a[p], s2+=a[p];
        f[i]=p-1;
        s1+=a[i];
    }
    f1(i, n) cout << f[i] << ' ';
    cout << '\n';
    for (int i=1; i<=n-2; i++)
    {
        int s1=s[i], s2=s[f[i]]-s[i], s3=s[n]-s[f[i]];
        int ma=max(s1, max(s2,s3));
        int mi=min(s1, min(s2,s3));
        ans = min(ans, ma-mi);
        if (f[i]>i+1)
        {
            s1=s[i], s2=s[f[i]-1]-s[i], s3=s[n]-s[f[i]-1];
            ma=max(s1, max(s2,s3));
            int mi=min(s1, min(s2,s3));
            ans = min(ans, ma-mi);
        }
    }
    cout << ans;
    return 0;
}
    