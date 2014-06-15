#include <cstdio>
#include <cmath>
inline double sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double calc(double p,double n)
{
    return((1-pow(p,n))/(1-p));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double p;
        int n,m;
        scanf("%lf%d%d",&p,&n,&m);
        double ans;
        if (sign(p-1)==0)
            ans=m;
        else if (sign(p)==0)
            ans=n;
        else
        {
            double c1=calc(1-p,n-1),c2=calc(p,m-1);
            double x=(c1*p*c2+c1)/(1-c1*p*c2*(1-p));
            double y=c2*(1-p)*x+c2;
            ans=(1-p)*x+p*y+1;
        }
        static int id=0;
        printf("Case %d: %.10f\n",++id,ans);
    }
    return(0);
}

