#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int c[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[110][100],id[110][110],to[210][2],f[210][130],pre[210][130][4];
char b[110][110];
inline bool update(int x1,int y1,int x2,int y2,int value)
{
    int y=y1|y2;
    if (f[x1][y1]+f[x2][y2]+value<f[x2][y])
    {
        f[x2][y]=f[x1][y1]+f[x2][y2]+value;
        pre[x2][y][0]=x1;
        pre[x2][y][1]=y1;
        pre[x2][y][2]=x2;
        pre[x2][y][3]=y2;
        return(true);
    }
    return(false);
}
void print(int x,int y)
{
    if (x==0)
        return;
    b[to[x][0]][to[x][1]]='X';
    print(pre[x][y][0],pre[x][y][1]);
    print(pre[x][y][2],pre[x][y][3]);
}
queue <int> Q;
bool in[210];
void spfa(int P,int n,int m)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            Q.push(id[i][j]);
    while (!Q.empty())
    {
        int x0=to[Q.front()][0],y0=to[Q.front()][1];
        in[Q.front()]=false;
        Q.pop();
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x==0 || x>n || y==0 || y>m)
                continue;
            if (update(id[x0][y0],P,id[x][y],0,a[x][y]) && !in[id[x][y]])
            {
                in[id[x][y]]=true;
                Q.push(id[x][y]);
            }
        }
    }
}
int main()
{
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    int t=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            t++;
            id[i][j]=t;
            to[t][0]=i,to[t][1]=j;
            b[i][j]='.';
        }
    memset(f,63,sizeof(f));
    int inf=f[0][0];
    for (int i=1;i<=t;i++)
        f[i][0]=0;
    for (int i=0;i<K;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        f[id[x][y]][1<<i]=a[x][y];
    }
    for (int i=1;i<1<<K;i++)
    {
        spfa(i,n,m);
        for (int j=1;j<=n;j++)
            for (int k=1;k<=m;k++)
            {
                if (f[id[j][k]][i]==inf)
                    continue;
                for (int l=1;l<1<<K;l++)
                {
                    if (i&l)
                        continue;
                    if (j<n)
                        update(id[j][k],i,id[j+1][k],l,0);
                    if (k<m)
                        update(id[j][k],i,id[j][k+1],l,0);
                    if (j>1)
                        update(id[j][k],i,id[j-1][k],l,0);
                    if (k>1)
                        update(id[j][k],i,id[j][k-1],l,0);
                }
            }
    }
    int ans=inf,k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (f[id[i][j]][(1<<K)-1]<ans)
            {
                ans=f[id[i][j]][(1<<K)-1];
                k=id[i][j];
            }
    printf("%d\n",ans);
    print(k,(1<<K)-1);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            printf("%c",b[i][j]);
        printf("\n");
    }
    return(0);
}

