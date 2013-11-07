#include <cstdio>
const int N=100010;
int len[N],gap[N],l[N],r[N];
int check(double step,int n)
{
    double now=0;
    for (int i=1;i<=n;i++)
    {
        if (now<l[i])
            return(-1);
        if (now>r[i])
            return(1);
        now+=step;
    }
    return(0);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&len[i]);
        for (int i=2;i<=n;i++)
            scanf("%d",&gap[i]);
        l[1]=0,r[1]=len[1];
        for (int i=2;i<=n;i++)
        {
            l[i]=r[i-1]+gap[i];
            r[i]=l[i]+len[i];
        }
        double ans=-1,l=0,r=1e10;
        for (int T=1;T<=100;T++)
        {
            double mid=(l+r)/2;
            int p=check(mid,n);
            if (p>=0)
            {
                if (p==0)
                    ans=mid;
                r=mid;
            }
            else
                l=mid;
        }
        if (ans<0)
            printf("impossible\n");
        else
            printf("%.2f\n",ans);
    }
    return(0);
}

