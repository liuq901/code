#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;
double f[4100][20];
int a[20];
char buf[1000000];
int main()
{
    int L;
    while (scanf("%d",&L)==1)
    {
        gets(buf);
        stringstream sin(buf);
        int x,n=0;
        while (sin>>x)
            a[++n]=x;
        for (int i=0;i<1<<n;i++)
            for (int j=1;j<=n;j++)
                f[i][j]=1e100;
        for (int i=1;i<=n;i++)
            f[1<<i-1][i]=2*a[i];
        for (int i=0;i<1<<n;i++)
            for (int j=1;j<=n;j++)
            {
                if (f[i][j]==1e100)
                    continue;
                for (int k=1;k<=n;k++)
                {
                    if (i>>k-1&1)
                        continue;
                    f[i|1<<k-1][k]=min(f[i|1<<k-1][k],f[i][j]+2*sqrt(double(a[j]*a[k]))-a[j]+a[k]);
                }
            }
        double ans=1e100;
        for (int i=1;i<=n;i++)
            ans=min(ans,f[(1<<n)-1][i]);
        printf("%s\n",ans<=L?"OK":"NA");
    }
    return(0);
}

