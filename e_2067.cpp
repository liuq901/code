#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(double x1,double y1,double x2,double y2)
{
    return(sqrt(sqr(x1-x2)+sqr(y1-y2)));
}
double cost[1010],a[1010][1010];
int X[1010],Y[1010];
bool use[1010];
double prim(int n)
{
    for (int i=0;i<=n;i++)
        cost[i]=1e26;
    cost[1]=0;
    double ans=0;
    for (int i=1;i<=n;i++)
    {
        int k=0;
        for (int j=1;j<=n;j++)
            if (!use[j] && cost[j]<cost[k])
                k=j;
        use[k]=true;
        ans+=cost[k];
        for (int j=1;j<=n;j++)
            cost[j]=min(cost[j],a[k][j]);
    }
    return(ans);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&X[i],&Y[i]);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            a[i][j]=a[j][i]=dist(X[i],Y[i],X[j],Y[j]);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=0;
    }
    printf("%.2f\n",prim(n));
    return(0);
}

