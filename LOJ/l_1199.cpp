#include <cstdio>
int vis[10010],sg[10010];
void init()
{
    const int n=10000;
    for (int i=1;i<=10000;i++)
    {
        for (int j=1;j<i;j++)
        {
            if (j==i-j)
                continue;
            vis[sg[j]^sg[i-j]]=i;
        }
        for (int j=0;;j++)
            if (vis[j]!=i)
            {
                sg[i]=j;
                break;
            }
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans^=sg[x];
        }
        static int id=0;
        printf("Case %d: %s\n",++id,ans?"Alice":"Bob");
    }
    return(0);
}

