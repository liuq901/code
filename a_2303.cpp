#include <cstdio>
#include <cstring>
const double eps=1e-8;
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
double t[110],p[110],f[60][60],a[110][60];
int b[110];
int main()
{
    int n,m,L;
    scanf("%d%d%d",&n,&m,&L);
    for (int i=1;i<=n;i++)
    {
        int P,v;
        scanf("%d%d%d",&P,&b[i],&v);
        p[i]=P/100.0,t[i]=double(L)/v;
    }
    for (int T=1;T<=n;T++)
    {
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for (int i=1;i<=m;i++)
            for (int j=0;j<=i;j++)
            {
                if (i>j)
                    f[i][j]+=f[i-1][j]*(1-p[T]);
                if (j>=1)
                    f[i][j]+=f[i-1][j-1]*p[T];
            }
        for (int i=0;i<=m;i++)
            a[T][i]=f[m][i];
    }
    for (int i=1;i<=n;i++)
    {
        double ans=0;
        for (int j=0;j<=m;j++)
        {
            double now=t[i]+b[i]*j,p=a[i][j];
            for (int k=1;k<=n;k++)
            {
                if (i==k)
                    continue;
                double sum=0;
                for (int l=m;l>=0;l--)
                {
                    double _now=t[k]+b[k]*l;
                    if (sign(now-_now)!=-1)
                        break;
                    sum+=a[k][l];
                }
                p*=sum;
            }
            ans+=p;
        }
        printf("%.8f\n",ans);
    }
    return(0);
}

