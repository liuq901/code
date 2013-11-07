#include <cstdio>
const int mod=10000;
int main()
{
    int n;
    scanf("%d",&n);
    int a,b,c,d;
    a=b=c=d=1;
    for (int i=1;i<=n;i++)
    {
        b=b*2%mod;
        c=c*3%mod;
        d=d*4%mod;
    }
    a=(a+b+c+d)%mod;
    int ans=0;
    while (a%10==0)
    {
        ans++;
        a/=10;
    }
    printf("%d\n",ans);
    return(0);
}

