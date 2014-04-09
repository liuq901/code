#include <cstdio>
#include <cstring>
#include <cctype>
const int c[8][2]={{-1,2},{-1,-2},{1,2,},{1,-2},{-2,1},{-2,-1},{2,1},{2,-1}};
int n,m,d[20][20],q[110][2];
char a[20][20];
int bfs(int Sx,int Sy)
{
    int l,r;
    q[l=r=1][0]=Sx,q[1][1]=Sy;
    memset(d,-1,sizeof(d));
    d[Sx][Sy]=0;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<8;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>=1 && x<=n && y>=1 && y<=m && d[x][y]==-1)
            {
                d[x][y]=d[x0][y0]+1;
                q[++r][0]=x,q[r][1]=y;
            }
        }
    }
    int ret=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (isdigit(a[i][j]))
            {
                int x=a[i][j]-'0';
                if (d[i][j]==-1)
                    return(-1);
                ret+=(d[i][j]+x-1)/x;
            }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int ans=-1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int now=bfs(i,j);
                if (now!=-1 && (ans==-1 || now<ans))
                    ans=now;
            }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

