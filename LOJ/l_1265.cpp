#include <cstdio>
#include <algorithm>
using namespace std;
double c[2010],f[1010][1010];
bool vis[1010][1010];
void init()
{
    const int n=2001;
    for (int i=0;i<=n;i++)
        c[i]=i*(i-1)/2;
}
double dp(int n,int m)
{
    if (n<0 || m<0)
        return(0);
    if (vis[n][m])
        return(f[n][m]);
    vis[n][m]=true;
    double &ret=f[n][m];
    if (n==0)
        ret=1;
    else
    {
        double p2=n*m/c[n+m+1];
        double p3=c[m]/c[n+m+1];
        double p4=m/c[n+m+1];
        double p5=c[n]/c[n+m+1];
        double tmp=p2*dp(n,m-1)+p5*dp(n-2,m);
        ret=max((tmp+p4*dp(n,m-1))/(1-p3),tmp/(1-p3-p4));
    }
    return(ret);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        static int id=0;
        printf("Case %d: %.10f\n",++id,dp(n,m));
    }
    return(0);
}

