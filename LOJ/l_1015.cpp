#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x>0)
                sum+=x;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,sum);
    }
    return(0);
}

