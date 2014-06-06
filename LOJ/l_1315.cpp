#include <cstdio>
#include <cstring>
const int c[6][2]={{1,-2},{-1,-2},{-1,-3},{-2,-1},{-3,-1},{-2,1}};
int f[1000][1000];
int sg(int x0,int y0)
{
    if (f[x0][y0]!=-1)
        return(f[x0][y0]);
    bool vis[10]={0};
    for (int i=0;i<6;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>=0 && y>=0)
            vis[sg(x,y)]=true;
    }
    for (int i=0;;i++)
        if (!vis[i])
            return(f[x0][y0]=i);
}
int main()
{
    int T;
    scanf("%d",&T);
    memset(f,-1,sizeof(f));
    while (T--)
    {
        int n,ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ans^=sg(x,y);
        }
        static int id=0;
        printf("Case %d: %s\n",++id,ans?"Alice":"Bob");
    }
    return(0);
}

