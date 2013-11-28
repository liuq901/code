#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,trea[20][2],a[510][510],f[1100][20],d[20][510][510],q[250010][2];
char buf[510];
inline bool update(int &a,int b)
{
    if (a==-1 || b<a)
    {
        a=b;
        return(true);
    }
    return(false);
}
void bfs(int id,int Sx,int Sy)
{
    memset(d[id],-1,sizeof(d[id]));
    d[id][Sx][Sy]=0;
    int l=1,r=1;
    q[1][0]=Sx,q[1][1]=Sy;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x==0 || x>n || y==0 || y>m || a[x][y]==-1)
                continue;
            if ((a[x0][y0]==5 || a[x0][y0]==i) && update(d[id][x][y],d[id][x0][y0]+1))
                q[++r][0]=x,q[r][1]=y;
        }
    }
}
int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        int K=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf+1);
            for (int j=1;j<=m;j++)
                if (buf[j]=='$')
                {
                    trea[++K][0]=i,trea[K][1]=j;
                    a[i][j]=5;
                }
                else if (buf[j]=='0')
                    a[i][j]=5;
                else if (buf[j]=='U')
                    a[i][j]=0;
                else if (buf[j]=='D')
                    a[i][j]=1;
                else if (buf[j]=='L')
                    a[i][j]=2;
                else if (buf[j]=='R')
                    a[i][j]=3;
                else
                    a[i][j]=-1;
        }
        int Sx,Sy,Tx,Ty;
        scanf("%d%d%d%d",&Sx,&Sy,&Tx,&Ty);
        if (a[Sx][Sy]==-1 || a[Tx][Ty]==-1)
            printf("-1\n");
        else
        {
            for (int i=1;i<=K;i++)
                bfs(i,trea[i][0],trea[i][1]);
            bfs(0,Sx,Sy);
            memset(f,-1,sizeof(f));
            for (int i=1;i<=K;i++)
                f[1<<i-1][i]=d[0][trea[i][0]][trea[i][1]];
            for (int i=0;i<1<<K;i++)
                for (int j=1;j<=K;j++)
                {
                    if (f[i][j]==-1)
                        continue;
                    for (int k=1;k<=K;k++)
                    {
                        if (i>>k-1&1)
                            continue;
                        if (d[j][trea[k][0]][trea[k][1]]!=-1)
                            update(f[i|1<<k-1][k],f[i][j]+d[j][trea[k][0]][trea[k][1]]);
                    }
                }
            int ans0=0,ans1=d[0][Tx][Ty];
            for (int i=0;i<1<<K;i++)
                for (int j=1;j<=K;j++)
                {
                    if (f[i][j]==-1 || d[j][Tx][Ty]==-1)
                        continue;
                    int p=__builtin_popcount(i);
                    if (p>ans0)
                        ans0=p,ans1=f[i][j]+d[j][Tx][Ty];
                    else if (p==ans0)
                        update(ans1,f[i][j]+d[j][Tx][Ty]);
                }
            printf("%d\n",ans1+ans0*2);
        }
    }
    return(0);
}

