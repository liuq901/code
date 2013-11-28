#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int sum=0,p;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
            if (i==1)
                p=x;
        }
        static int id=0;
        printf("Case %d: %.6f\n",++id,double(p)/sum);
    }
    return(0);
}

