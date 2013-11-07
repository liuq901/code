#include <cstdio>
int f[10000010];
int main()
{
    int n,mod;
    scanf("%d%d",&n,&mod);
    f[2]=1%mod;
    for (int i=3;i<=n;i++)
    {
        f[i]=f[i-1];
        if (i%2==0)
            f[i]+=f[i/2];
        if (f[i]>=mod)
            f[i]-=mod;
    }
    printf("%d\n",f[n]);
    return(0);
}

