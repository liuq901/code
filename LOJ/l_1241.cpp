#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,x=2,ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int y;
            scanf("%d",&y);
            ans+=(y-x+4)/5;
            x=y;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

