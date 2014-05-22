#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[100010],dep[100010],a[200010][3],fa[100010][17],mi[100010][17],ma[100010][17];
void dfs(int x,int father)
{
    for (int i=1;i<=16;i++)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
        mi[x][i]=min(mi[x][i-1],mi[fa[x][i-1]][i-1]);
        ma[x][i]=max(ma[x][i-1],ma[fa[x][i-1]][i-1]);
    }
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dep[y]=dep[x]+1;
        fa[y][0]=x;
        mi[y][0]=ma[y][0]=a[i][1];
        dfs(y,x);
    }
}
void query(int x,int y)
{
    if (dep[x]<dep[y])
        swap(x,y);
    int p=1<<30,q=-1;
    for (int i=16;i>=0;i--)
        if (dep[fa[x][i]]>=dep[y])
        {
            p=min(p,mi[x][i]);
            q=max(q,ma[x][i]);
            x=fa[x][i];
        }
    if (x!=y)
    {
        for (int i=16;i>=0;i--)
            if (fa[x][i]!=fa[y][i])
            {
                p=min(p,min(mi[x][i],mi[y][i]));
                q=max(q,max(ma[x][i],ma[y][i]));
                x=fa[x][i],y=fa[y][i];
            }
        p=min(p,min(mi[x][0],mi[y][0]));
        q=max(q,max(ma[x][0],ma[y][0]));
    }
    printf("%d %d\n",p,q);
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
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
        }
        dep[1]=1;
        dfs(1,0);
        int Q;
        scanf("%d",&Q);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            query(x,y);
        }
    }
    return(0);
}

