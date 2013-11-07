#include <cstdio>
#include <cmath>
double Log[400010];
double calc(int n,double p,double q)
{
    if (fabs(p)<1e-8)
        return(0);
    if (fabs(q)<1e-8)
        return(n);
    double ret=0,ans=(n+1)*log(q),pp=log(p);
    for (int i=n;i;i--)
    {
        ret+=exp(ans+Log[i]);
        ans+=pp+Log[2*n-i+1]-Log[n-i+1];
    }
    return(ret);
}
int main()
{
    for (int i=1;i<=400000;i++)
        Log[i]=log(double(i));
    int n;
    double p;
    while (scanf("%d%lf",&n,&p)==2)
    {
        static int id=0;
        printf("Case %d: %.6f\n",++id,calc(n,p,1-p)+calc(n,1-p,p));
    }
    return(0);
}

