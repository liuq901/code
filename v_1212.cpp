#include <cstdio>
#include <cmath>
#include <cstring>
int b[1010],a[1010][1010];
double X[1010],Y[1010];
bool f[1010];
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(double x1,double y1,double x2,double y2)
{
    return(sqrt(sqr(x1-x2)+sqr(y1-y2)));
}
bool hungary(int x)
{
    if (x==0)
        return(true);
    for (int i=1;i<=a[x][0];i++)
    {
        int y=a[x][i];
        if (f[y])
            continue;
        f[y]=true;
        if (hungary(b[y]))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
int main()
{
    int n,m,T;
    scanf("%d%d%d",&n,&m,&T);
    for (int i=1;i<=m;i++)
        scanf("%lf%lf",&X[i],&Y[i]);
    for (int i=1;i<=n;i++)
    {
        double x,y,v;
        scanf("%lf%lf%lf",&x,&y,&v);
        for (int j=1;j<=m;j++)
            if (sign(T*v-dist(X[j],Y[j],x,y))>=0)
                a[i][++a[i][0]]=j;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        memset(f,0,sizeof(f));
        ans+=hungary(i);
    }
    printf("%d\n",ans);
    return(0);
}

