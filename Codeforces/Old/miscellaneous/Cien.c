#include<stdio.h>
#include<math.h>
#include<string.h>
#include<limits.h>

#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,b,a) for(int i=b;i>=a;--i)


int t,n,a,b,ans,max1,res,tmp;
char s[1000];

int main(){
    scanf("%d",&n);
    ans=0;
    for (int i=0;i<n;i++){
        int sum=0;
        for (int j=0;j<3;j++){
            scanf("%d",&res);
            sum+=res;
        }
        if (sum>=2) ans++;
    }
    printf("%d",ans);
    return 0;
}