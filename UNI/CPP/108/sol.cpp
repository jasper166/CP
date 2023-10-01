#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

bool isPrime(int n)
{
	if(n<2) return false;
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

bool tanggiam(int n)
{
	int t=0,g=0;
	while(n>9)
	{

		if((n%10)>(n/10)%10) t++;
		else if((n%10)<(n/10)%10) g++;
		else if((n%10)==(n/10)%10) return false;
		n/=10;
	}
	if(t!=0&&g!=0) return false;
	return true;
}

int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		int n, CNT=0;
		cin >> n;
		int a=pow(10,n-1);
		int b=pow(10,n)-1;
		for(int i=a; i<=b;i++)
		{
			if(tanggiam(i))
			if(isPrime(i)){
				 CNT++;
			}
		}
		cout<<CNT<<endl;
	}
 } 

