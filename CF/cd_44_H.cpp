#include <cstdio>
#include <cstring>
typedef long long ll;
char buf[60];
int a[60];
ll f[60][20];
int calc(int n)
{
    for (int i=2;i<=n;i++)
    {
        int x=a[i-1]+a[i];
        if (x%2==0 && x/2!=a[i] || x%2==1 && x/2!=a[i] && x/2+1!=a[i])
            return(0);
    }
    return(1);
}
int main()
{
    scanf("%s",buf);
    int n=strlen(buf);
    for (int i=1;i<=n;i++)
        a[i]=buf[i-1]-'0';
    for (int i=0;i<10;i++)
        f[1][i]=1;
    for (int i=2;i<=n;i++)
        for (int j=0;j<10;j++)
        {
            int x=a[i]+j;
            if (x%2==0)
                f[i][x/2]+=f[i-1][j];
            else
            {
                f[i][x/2]+=f[i-1][j];
                f[i][x/2+1]+=f[i-1][j];
            }
        }
    ll ans=0;
    for (int i=0;i<10;i++)
        ans+=f[n][i];
    printf("%I64d\n",ans-calc(n));
    return(0);
}

