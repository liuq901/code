#include <cstdio>
const double eps=1e-8;
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
int a[110];
double ans[110];
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    double ave=double(sum)/(n+1),tot=0;
    for (int i=1;i<=n;i++)
        if (sign(a[i]-ave)==1)
            tot+=a[i]-ave;
    double money=100.0/tot;
    for (int i=1;i<=n;i++)
    {
        if (sign(a[i]-ave)<=0)
            continue;
        ans[i]=money*(a[i]-ave);
    }
    for (int i=1;i<=n;i++)
        printf("%d%c",int(ans[i]+eps),i==n?'\n':' ');
    return(0);
}

