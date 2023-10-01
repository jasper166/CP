#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int a[10001]={0};

//bool tanggiam(int n)
//{
//	int t=0,g=0;
//	while(n>9)
//	{
//
//		if((n%10)>(n/10)%10) t++;
//		else if((n%10)<(n/10)%10) g++;
//		else if((n%10)==(n/10)%10) return false;
//		n/=10;
//	}
//	if(t!=0&&g!=0) return false;
//	return true;
//}

int main()
{	
	for(int i=2;i*i<=10000; i++)
	{
		if(!a[i])
		for(int j=i*i; j<=10000;j+=i)
		{
			if(a[j]!=0) continue;
			a[j]=i;
		}
	}
	a[0]=1;
	a[1]=1;
	int t;
	cin >>t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 1;i<=n; i++){
			if(a[i]==0) cout << i<<" ";
			else cout << a[i]<<" ";
		}
		cout <<endl;
	}
 } 

