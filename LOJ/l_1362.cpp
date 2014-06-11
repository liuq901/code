#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int b[10][10],f[260][10][10];
char a[10][10];
bool in[10][10];
void spfa(int id)
{
    queue <pair <int,int> > Q;
    for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++)
        {
            in[i][j]=true;
            Q.push(make_pair(i,j));
        }
    while (!Q.empty())
    {
        int x0=Q.front().first,y0=Q.front().second;
        in[x0][y0]=false;
        Q.pop();
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=8 && y>0 && y<=8 && f[id][x0][y0]+b[x][y]+1<f[id][x][y])
            {
                f[id][x][y]=f[id][x0][y0]+b[x][y]+1;
                if (!in[x][y])
                {
                    in[x][y]=true;
                    Q.push(make_pair(x,y));
                }
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int pl,pw;
        scanf("%d%d",&pl,&pw);
        for (int i=1;i<=8;i++)
            scanf("%s",a[i]+1);
        memset(f,63,sizeof(f));
        memset(b,0,sizeof(b));
        int cnt=0,Sx,Sy;
        for (int i=1;i<=8;i++)
            for (int j=1;j<=8;j++)
                if (a[i][j]=='G')
                    Sx=i,Sy=j;
                else if (a[i][j]=='H')
                    f[1<<cnt++][i][j]=0;
                else if (a[i][j]=='W')
                    b[i][j]=pw;
                else
                    b[i][j]=pl;
        for (int i=0;i<1<<cnt;i++)
        {
            for (int j=1;j<=8;j++)
                for (int k=1;k<=8;k++)
                    for (int l=i;l;l=i&l-1)
                        f[i][j][k]=min(f[i][j][k],f[l][j][k]+f[i^l][j][k]-b[j][k]);
            spfa(i);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[(1<<cnt)-1][Sx][Sy]);
    }
    return(0);
}

