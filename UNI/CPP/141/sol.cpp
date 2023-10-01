#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a[100];
	a[0]=0;
	a[1]=1;
	for(int i=2; i<100;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		bool c = false;
		cin >> n;
		for(int i=0; a[i]<=n;i++)
		{
			if(a[i]==n) c=true;
		}
		if(c) cout << "YES\n";
		else cout << "NO\n";
	}
}

