#include <cstdio>
#include <cmath>
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double sqr(double x)
{
    return(x*x);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        double best=1e100;
        int ans;
        for (int i=1;i<=n;i++)
        {
            int id,x,y;
            scanf("%d%d%d",&id,&x,&y);
            double now=y/(sqr(x/100.0));
            double delta=fabs(now-22);
            if (sign(delta-best)<0 || sign(delta-best)==0 && id<ans)
                best=delta,ans=id;
        }
        printf("%d\n",ans);
    }
    return(0);
}

