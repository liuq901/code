#include <cstdio>
const int n=60000,mod=1000000;
int f[n+10];
int main()
{
    f[0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=n-i;j++)
            f[i+j]=(f[i+j]+f[j])%mod;
    for (int i=1;i<=n;i++)
        if (f[i]==0)
        {
            printf("%d\n",i);
            break;
        }
    return(0);
}

