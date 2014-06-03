#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
int b[10010],a[30010][4],d[10010][20];
bool in[10010][20];
int spfa(int S,int T,int m)
{
    memset(d,63,sizeof(d));
    d[S][0]=0;
    in[S][0]=true;
    queue <pair <int,int> > Q;
    Q.push(make_pair(S,0));
    while (!Q.empty())
    {
        int x=Q.front().first,t=Q.front().second;
        in[x][t]=false;
        Q.pop();
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (t+a[i][2]<=m && d[x][t]+a[i][1]<d[y][t+a[i][2]])
            {
                d[y][t+a[i][2]]=d[x][t]+a[i][1];
                if (!in[y][t+a[i][2]])
                {
                    in[y][t+a[i][2]]=true;
                    Q.push(make_pair(y,t+a[i][2]));
                }
            }
        }
    }
    int ans=d[0][0];
    for (int i=0;i<=m;i++)
        if (d[T][i]<ans)
            ans=d[T][i];
    if (ans==d[0][0])
        ans=-1;
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,K,D;
        scanf("%d%d%d%d",&n,&m,&K,&D);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i][0]=y,a[i][1]=z,a[i][2]=0,a[i][3]=b[x],b[x]=i;
        }
        for (int i=1;i<=K;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i+m][0]=y,a[i+m][1]=z,a[i+m][2]=1,a[i+m][3]=b[x],b[x]=i+m;
        }
        static int id=0;
        printf("Case %d: ",++id);
        int ans=spfa(1,n,D);
        if (ans==-1)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

