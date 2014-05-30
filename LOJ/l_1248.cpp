#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        double ans=0;
        for (int i=1;i<=n;i++)
        {
            double p=(i-1.0)/n;
            ans+=1/(1-p);
        }
        static int id=0;
        printf("Case %d: %.10f\n",++id,ans);
    }
    return(0);
}

