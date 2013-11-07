#include <cstdio>
#include <cstring>
const int mod=1000000007;
char a[5010],b[5010];
int n,m,c[5010],f[5010][5010];
int main()
{
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1),m=strlen(b+1);
    for (int i=1;i<=m;i++)
    {
        c[i]=c[i-1];
        if (b[i]==a[1])
        {
            f[1][i]=1;
            c[i]++;
        }
    }
    for (int i=2;i<=n;i++)
    {
        for (int j=m;j;j--)
        {
            c[j]=0;
            if (a[i]==b[j])
            {
                f[i][j]=(c[j-1]+1)%mod;
                c[j]=f[i][j];
            }
        }
        for (int j=1;j<=m;j++)
            c[j]=(c[j-1]+c[j])%mod;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            ans=(ans+f[i][j])%mod;
    printf("%d\n",ans);
    return(0);
}

