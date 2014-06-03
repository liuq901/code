#include <cstdio>
#include <cmath>
const int mod=1000;
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ret*x%mod;
        x=x*x%mod;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        static int id=0;
        printf("Case %d: %d %03d\n",++id,int(pow(10.0,fmod(K*log10(double(n)),1.0))*100),power(n%mod,K));
    }
}

