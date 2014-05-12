#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int b[5010],d[5010][2],a[200010][3];
bool in[5010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
        }
        memset(d,63,sizeof(d));
        d[1][0]=0;
        queue <int> Q;
        Q.push(1);
        in[1]=true;
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            in[x]=false;
            for (int i=b[x];i;i=a[i][2])
            {
                int y=a[i][0];
                for (int j=0;j<2;j++)
                {
                    if (d[x][j]+a[i][1]<d[y][0])
                    {
                        d[y][1]=d[y][0];
                        d[y][0]=d[x][j]+a[i][1];
                        if (!in[y])
                        {
                            in[y]=true;
                            Q.push(y);
                        }
                    }
                    if (d[x][j]+a[i][1]>d[y][0] && d[x][j]+a[i][1]<d[y][1])
                    {
                        d[y][1]=d[x][j]+a[i][1];
                        if (!in[y])
                        {
                            in[y]=true;
                            Q.push(y);
                        }
                    }
                }
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,d[n][1]);
    }
    return(0);
}

