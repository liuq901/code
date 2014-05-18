#include <cstdio>
#include <cstring>
int v[100010],b[100010],a[100010][2],f[100010][17];
void dfs(int x)
{
    for (int i=1;i<=16;i++)
        f[x][i]=f[f[x][i-1]][i-1];
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        f[y][0]=x;
        dfs(y);
    }
}
int query(int x,int value)
{
    for (int i=16;i>=0;i--)
        if (v[f[x][i]]>=value)
            x=f[x][i];
    return(x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        memset(b,0,sizeof(b));
        v[1]=1;
        for (int i=2;i<=n;i++)
        {
            int x;
            scanf("%d%d",&x,&v[i]);
            x++;
            a[i][0]=i,a[i][1]=b[x],b[x]=i;
        }
        dfs(1);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",query(x+1,y)-1);
        }
    }
    return(0);
}

