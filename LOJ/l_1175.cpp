#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[210][210];
int f[210][210],d[210][210];
int bfs(int n,int m)
{
    queue <pair <int,int> > Q;
    memset(f,-1,sizeof(f));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='F')
            {
                f[i][j]=0;
                Q.push(make_pair(i,j));
            }
    while (!Q.empty())
    {
        int x0=Q.front().first,y0=Q.front().second;
        Q.pop();
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=m && a[x][y]!='#' && f[x][y]==-1)
            {
                f[x][y]=f[x0][y0]+1;
                Q.push(make_pair(x,y));
            }
        }
    }
    memset(d,-1,sizeof(d));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='J')
            {
                d[i][j]=1;
                Q.push(make_pair(i,j));
            }
    while (!Q.empty())
    {
        int x0=Q.front().first,y0=Q.front().second;
        Q.pop();
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x==0 || x>n || y==0 || y>m)
                return(d[x0][y0]);
            if (a[x][y]!='#' && d[x][y]==-1 && (f[x][y]==-1 || d[x0][y0]<f[x][y]))
            {
                d[x][y]=d[x0][y0]+1;
                Q.push(make_pair(x,y));
            }
        }
    }
    return(-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int ans=bfs(n,m);
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

