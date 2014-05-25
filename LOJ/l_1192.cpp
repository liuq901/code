#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ans^=y-x-1;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,ans?"Alice":"Bob");
    }
    return(0);
}

