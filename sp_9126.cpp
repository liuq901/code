#include <cstdio>
#include <cstring>
int d[100010],q[100010],b[100010],a[200010][2];
void bfs(int x)
{
    int l,r;
    memset(d,0,sizeof(d));
    d[x]=1,q[l=r=1]=x;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (d[y])
                continue;
            d[y]=d[x]+1;
            q[++r]=y;
        }
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
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
        }
        bfs(1);
        bfs(q[n]);
        printf("%d\n",d[q[n]]>>1);
    }
    return(0);
}

