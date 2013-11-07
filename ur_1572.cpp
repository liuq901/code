#include <cstdio>
#include <cmath>
const double eps=1e-8;
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
int main()
{
    int kind,len,n,ans=0;
    scanf("%d%d%d",&kind,&len,&n);
    double limit;
    if (kind==1)
        limit=2*len;
    else if (kind==2)
        limit=sqrt(2.0)*len;
    else
        limit=len;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&kind,&len);
        double now;
        if (kind==1)
            now=2*len;
        else if (kind==2)
            now=len;
        else
            now=len*sqrt(3.0)/2;
        ans+=sign(limit-now)>=0;
    }
    printf("%d\n",ans);
    return(0);
}

