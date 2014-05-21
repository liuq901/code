#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int inf,n,m,d[30][30],q[630][2];
char a[30][30];
void bfs(int Sx,int Sy,int R)
{
    int l,r;
    q[l=r=1][0]=Sx,q[1][1]=Sy;
    memset(d,63,sizeof(d));
    inf=d[0][0];
    d[Sx][Sy]=0;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=R && y>0 && y<=R && a[x][y]!='#' && d[x0][y0]+1<d[x][y])
            {
                d[x][y]=d[x0][y0]+1;
                q[++r][0]=x,q[r][1]=y;
            }
        }
    }
}
int pos[60][2],w[60][60];
void build(int R)
{
    m=0;
    for (int i=1;i<=R;i++)
        for (int j=1;j<=R;j++)
            if (a[i][j]=='H')
                pos[++m][0]=i,pos[m][1]=j;
    n=0;
    for (int i=1;i<=R;i++)
        for (int j=1;j<=R;j++)
            if (a[i][j]=='G')
            {
                bfs(i,j,R);
                n++;
                for (int k=1;k<=m;k++)
                    w[n][k]=d[pos[k][0]][pos[k][1]];
            }
}
int b[60];
bool vis[60];
bool hungary(int x,int limit)
{
    if (x==0)
        return(true);
    for (int y=1;y<=m;y++)
    {
        if (w[x][y]>limit || vis[y])
            continue;
        vis[y]=true;
        if (hungary(b[y],limit))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int R;
        scanf("%d",&R);
        for (int i=1;i<=R;i++)
            scanf("%s",a[i]+1);
        memset(w,-63,sizeof(w));
        build(R);
        int l=0,r=10000,ans=-1;
        while (l<=r)
        {
            int mid=l+r>>1;
            memset(b,0,sizeof(b));
            int sum=0;
            for (int i=1;i<=n;i++)
            {
                memset(vis,0,sizeof(vis));
                sum+=hungary(i,mid);
            }
            if (sum==m)
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("Vuter Dol Kupokat\n");
        else
            printf("%d\n",ans+1<<1);
    }
    return(0);
}

