#include <bits/stdc++.h>
using namespace std;

	int a[1005]={0};
int main()
{
	int t;
	cin >> t;

	int f1=0, f2=1, fn=0;
	a[0]=1;
	a[1]=1;
	while(fn<=1000)
	{
		fn=f1+f2;
		f1=f2;
		f2=fn;
		a[fn]=1;
	}
	while(t--)
	{
		int n;
		cin >> n;
		int b[n+3];
		for(int i=0; i<n; i++)
		{
			cin >> b[i];
			if(a[b[i]]==1)
			{
				cout<< b[i]<<" ";
			}
			
		}
		cout << endl;
	}
}

