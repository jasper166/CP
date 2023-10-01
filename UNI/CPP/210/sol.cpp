#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n], b[n];
		for(int i=0; i<n; i++) 
		cin >> a[i];
		int max=-1;
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				if(max<a[j]-a[i]) max=a[j]-a[i];
			}
		}
		cout << max << endl;
	}
}

