#include <cstdio>
#include <cstring>
int ans,d[20010],b[20010],a[40010][3];
void up(int x,int y)
{
    if (d[y]>0)
        d[x]+=d[y];
    else
        ans-=d[y]-1,d[x]++;
}
void down(int x,int y)
{
    if (d[y]<0)
        d[x]+=d[y];
    else
        d[x]--;
}
void dfs(int x,int father)
{
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dfs(y,x);
        a[i][1]?down(x,y):up(x,y);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            a[i][0]=y,a[i][1]=1,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=0,a[i+n][2]=b[y],b[y]=i+n;
        }
        ans=0;
        memset(d,0,sizeof(d));
        dfs(1,0);
        if (d[1]<0)
            ans-=d[1];
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

