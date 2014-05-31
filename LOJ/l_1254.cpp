#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
int v[110],b[110],d[110][110],a[2010][3];
bool in[110][110];
queue <pair <int,int> > Q;
int spfa(int m,int S,int T)
{
    memset(d,63,sizeof(d));
    d[S][0]=0;
    in[S][0]=true;
    Q.push(make_pair(S,0));
    while (!Q.empty())
    {
        int x=Q.front().first,k=Q.front().second;
        Q.pop();
        in[x][k]=false;
        if (k<m && d[x][k]+v[x]<d[x][k+1])
        {
            d[x][k+1]=d[x][k]+v[x];
            if (!in[x][k+1])
            {
                in[x][k+1]=true;
                Q.push(make_pair(x,k+1));
            }
        }
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (a[i][1]<=k && d[x][k]<d[y][k-a[i][1]])
            {
                d[y][k-a[i][1]]=d[x][k];
                if (!in[y][k-a[i][1]])
                {
                    in[y][k-a[i][1]]=true;
                    Q.push(make_pair(y,k-a[i][1]));
                }
            }
        }
    }
    if (d[T][0]==d[0][0])
        return(-1);
    return(d[T][0]);
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
            scanf("%d",&v[i]);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
        }
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int c,s,t;
            scanf("%d%d%d",&c,&s,&t);
            s++,t++;
            int ans=spfa(c,s,t);
            if (ans==-1)
                printf("impossible\n");
            else
                printf("%d\n",ans);
        }
    }
    return(0);
}

