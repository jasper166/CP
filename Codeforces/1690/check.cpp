/*
	www.youtube.com/YugiHackerChannel
	oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 50004
using namespace std;
int t, n, a[maxn], b[maxn];
void solve()
{
    cin >> n;
    f1 (i, n) cin >> a[i];
    f1 (i, n) cin >> b[i];
    int dis = -1, ma = 0;
    f1 (i, n)
    {
        if (a[i] < b[i])
        {
            cout << "NO"; el;
            return;
        }
        if (a[i] && b[i])
        {
            if (dis == -1) dis = a[i] - b[i];
            else if (dis != a[i] - b[i])
            {
                cout << "NO"; el;
                return;
            }
        }
        else ma = max(ma, a[i] - b[i]);
    }
    if (dis != -1 && ma > dis)
    {
        cout << "NO"; el;
        return;
    }
    cout << "YES"; el;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
}
