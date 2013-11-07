#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2510;
double a[N],s1[N],s2[N],f[N][60];
inline double sqr(double x)
{
    return(x*x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
int pos[N][60];
inline bool update(double &a,double b)
{
    if (sign(a-b)>0)
    {
        a=b;
        return(true);
    }
    return(false);
}
inline double calc(int l,int r)
{
    double a=r-l+1,b=-2*(s1[r]-s1[l-1]),c=s2[r]-s2[l-1],t=-b/2/a;
    return(a*sqr(t)+b*t+c);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int R,C,m,n=0;
        scanf("%d%d%d",&R,&C,&m);
        for (int i=1;i<=R;i++)
            for (int j=1;j<=C;j++)
            {
                double x;
                scanf("%lf",&x);
                a[++n]=x;
            }
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++)
        {
            s1[i]=s1[i-1]+a[i];
            s2[i]=s2[i-1]+sqr(a[i]);
        }
        for (int i=1;i<=n;i++)
            for (int j=0;j<=m;j++)
                f[i][j]=1e100;
        f[0][0]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=min(i,m);j++)
            {
                int begin=j==1?0:pos[i][j-1];
                for (int k=begin;k<i;k++)
                {
                    if (update(f[i][j],f[k][j-1]+calc(k+1,i)))
                        pos[i][j]=k;
                }
            }
        double ans=1e100;
        for (int i=1;i<=m;i++)
            ans=min(ans,f[n][i]);
        printf("%.2f\n",ans);
    }
    return(0);
}

