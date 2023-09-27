#include <bits/stdc++.h>
using namespace std;
const int m = 1e9+7;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n, x;
		cin >> n>> x;
		long long a[n];
		for(int i=0; i<n; i++) cin >> a[i];
		long long p =1;
		long long kq=0;
		for(int i=n-1; i>=0; i--)
		{
			kq = ((a[i]*p)+kq)%m;
			p*=x;
			p=p%m;
		}
		cout << kq<< endl;
	}
}

