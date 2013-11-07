#include <cstdio>
#include <cstring>
int tot,b[200010],a[1000000][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
}
bool in[200010];
int q[200010],d[200010];
int spfa(int S,int T)
{
    memset(d,-1,sizeof(d));
    d[S]=0;
    in[S]=true;
    int l=0,r=1;
    q[1]=S;
    while (l!=r)
    {
        l=l==200005?1:l+1;
        int x=q[l];
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y]==-1 || d[x]+a[i][1]<d[y])
            {
                d[y]=d[x]+a[i][1];
                if (!in[y])
                {
                    in[y]=true;
                    r=r==200005?1:r+1;
                    q[r]=y;
                }
            }
        }
    }
    return(d[T]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,C;
        scanf("%d%d%d",&n,&m,&C);
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x!=n)
                add(i,x+n+1,C);
            if (x!=1)
                add(i,x+n-1,C);
            add(x+n,i,0);
        }
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
            add(y,x,z);
        }
        static int id=0;
        printf("Case #%d: %d\n",++id,spfa(1,n));
    }
    return(0);
}

