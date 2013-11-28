#include <cstdio>
#include <algorithm>
using namespace std;
double a[30][3];
int Log(int x)
{
    int ans=0;
    while (x)
    {
        ans+=x&1;
        x>>=1;
    }
    return(ans);
}
int p[30];
double calc(int x,int n)
{
    int t=0;
    for (int i=1;i<=n;i++)
        if (x>>i-1&1)
            p[++t]=i;
    double ret=0;
    for (int i=1;i<=t;i++)
        for (int j=i+1;j<=t;j++)
            for (int k=0;k<3;k++)
            {
                int x=p[i],y=p[j];
                ret+=(a[x][k]-a[y][k])*(a[x][k]-a[y][k]);
            }
    return(ret);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=0;j<3;j++)
            scanf("%lf",&a[i][j]);
    double ans=0;
    for (int i=0;i<1<<n;i++)
    {
        if (Log(i)!=m)
            continue;
        ans=max(ans,calc(i,n));
    }
    printf("%.20f\n",ans);
    return(0);
}

