#include <cstdio>
#include <cmath>
const double eps=1e-8;
int x[110],y[110];
double p[110],f[110][110];
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(int a,int b)
{
    return(sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b])));
}
int main()
{
    int n,K,E;
    scanf("%d%d%d%d%d",&n,&K,&E,&x[0],&y[0]);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    double limit=1-E/1000.0,l=0,r=1000000;
    for (int T=0;T<100;T++)
    {
        double mid=(l+r)/2.0;
        for (int i=1;i<=n;i++)
        {
            double D=dist(0,i);
            if (sign(mid-D)>=0)
                p[i]=1;
            else if (sign(mid)==0)
                p[i]=0;
            else
                p[i]=exp(1-sqr(D)/sqr(mid));
        }
        f[0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=i;j++)
            {
                f[i][j]=0;
                if (j>0)
                    f[i][j]+=f[i-1][j-1]*p[i];
                if (i>j)
                    f[i][j]+=f[i-1][j]*(1-p[i]);
            }
        double ans=0;
        for (int i=K;i<=n;i++)
            ans+=f[n][i];
        if (ans>=limit)
            r=mid;
        else
            l=mid;
    }
    printf("%.10f\n",(l+r)/2);
    return(0);
}

