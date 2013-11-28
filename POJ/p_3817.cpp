#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int X[1010],Y[1010],p[1010],s[1010];
double f[1010],dis[1010][1010];
inline int sqr(int x)
{
    return(x*x);
}
inline double dist(int x,int y)
{
    return(sqrt(double(sqr(X[x]-X[y])+sqr(Y[x]-Y[y]))));
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&X[i],&Y[i],&p[i]);
            s[i]=s[i-1]+p[i];
        }
        X[0]=0,Y[0]=0;
        X[++n]=100,Y[n]=100;
        for (int i=0;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                dis[i][j]=dist(i,j);
        for (int i=0;i<=n;i++)
            f[i]=1e20;
        f[0]=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<i;j++)
                f[i]=min(f[i],f[j]+dis[j][i]+s[i-1]-s[j]+1);
        printf("%.3f\n",f[n]);
    }
    return(0);
}

