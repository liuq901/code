#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
int start,d[32770][20],pre[32770][20];
bool adj[20][20],lamp[20][20];
void print(int x,int y)
{
    if (x==start && y==1)
        return;
    int t=pre[x][y];
    t<0?print(x,-t):print(x^1<<t-1,y);
    if (t<0)
        printf("Move to room %d.\n",y);
    else if (x>>t-1&1)
        printf("Switch on room %d.\n",t);
    else
        printf("Switch off room %d.\n",t);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(adj,0,sizeof(adj));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            adj[x][y]=adj[y][x]=true;
        }
        start=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            start|=x<<i-1;
        }
        memset(lamp,0,sizeof(lamp));
        for (int i=1;i<=n;i++)
        {
            int K;
            scanf("%d",&K);
            for (int j=0;j<K;j++)
            {
                int x;
                scanf("%d",&x);
                lamp[i][x]=true;
            }
        }
        memset(d,-1,sizeof(d));
        d[start][1]=0;
        queue <pair <int,int> > Q;
        Q.push(make_pair(start,1));
        while (!Q.empty())
        {
            int state=Q.front().first,x=Q.front().second;
            Q.pop();
            for (int i=1;i<=n;i++)
            {
                if (!adj[x][i])
                    continue;
                int y=i;
                if (state>>y-1&1 && d[state][y]==-1)
                {
                    d[state][y]=d[state][x]+1;
                    pre[state][y]=-x;
                    Q.push(make_pair(state,y));
                }
            }
            for (int i=1;i<=n;i++)
            {
                if (!lamp[x][i])
                    continue;
                int y=i,now=state^1<<y-1;
                if (x!=y && d[now][x]==-1)
                {
                    d[now][x]=d[state][x]+1;
                    pre[now][x]=y;
                    Q.push(make_pair(now,x));
                }
            }
        }
        if (d[1<<n-1][n]!=-1)
        {
            printf("You can go home in %d steps.\n",d[1<<n-1][n]);
            print(1<<n-1,n);
        }
        else
        {
            bool flag=false;
            for (int i=0;i<1<<n;i++)
                if (d[i][n]!=-1)
                {
                    flag=true;
                    break;
                }
            printf("%s\n",flag?"You can not switch off all lights.":"Help me!");
        }
    }
    return(0);
}

