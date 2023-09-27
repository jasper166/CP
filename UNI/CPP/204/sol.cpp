#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long l, r;
		cin >> l>> r;
		int a[10000]={0};
		for(long long i=2; i*i<=r; i++)
		{
			for(long long j=max(i*i,(l+i-1)/i*i);j<=r;j+=i)
			{
				a[j-l]=1;
			}
		}
		if(1>=l) a[1-l] = 1;
		int cnt=0;
		for(long long i=l; i<=r; i++)
		{
			if(a[i-l]==0)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}

