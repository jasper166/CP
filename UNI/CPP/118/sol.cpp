#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >>t ;
	while(t--){
		long long n;
		cin >>n;
		int cnt=0;
		for(long long i=2; i*i <=n; i++){
			int c=0;
			while(n%i==0){
				n/=i;
				c++;
				cnt++;
			}
			if(c>1)cnt=4;
		}
		if(n>1) cnt++;
		if(cnt==3) cout <<"1";
		else cout << "0";
		cout << endl;
	}
} 


