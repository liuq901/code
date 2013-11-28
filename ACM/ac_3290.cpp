#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct state
{
    int x,y,t;
    state(int x,int y,int t):x(x),y(y),t(t){}
};
queue <state> Q;
int a[30][30],d[30][30][30],f[30][30][30];
inline int update(int &a,int b)
{
    if (a==-1 || b<a)
    {
        a=b;
        return(true);
    }
    return(false);
}
void bfs(int id,int Sx,int Sy,int T,int n)
{
    memset(d,-1,sizeof(d));
    memset(f[id],-1,sizeof(f[id]));
    Q.push(state(Sx,Sy,0));
    d[Sx][Sy][0]=0;
    while (!Q.empty())
    {
        int x0=Q.front().x,y0=Q.front().y,t=Q.front().t;
        update(f[id][x0][y0],d[x0][y0][t]);
        Q.pop();
        if (t==T)
            continue;
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=n && update(d[x][y][t+1],d[x0][y0][t]+a[x0][y0]))
                Q.push(state(x,y,t+1));
        }
    }
}
int main()
{
    while (1)
    {
        int n,F,T;
        scanf("%d%d%d",&n,&F,&T);
        if (n==0 && F==0 && T==0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for (int i=1;i<=F;i++)
        {
            int x0,y0;
            scanf("%d%d",&x0,&y0);
            bfs(i,x0+1,y0+1,T,n);
        }
        int ans=-1,x0,y0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                int now=0;
                for (int k=1;k<=F;k++)
                {
                    if (f[k][i][j]==-1)
                    {
                        now=-1;
                        break;
                    }
                    now+=f[k][i][j];
                }
                if (now!=-1 && update(ans,now))
                    x0=i,y0=j;
            }
        static int id=0;
        printf("Case #%d: ",++id);
        if (ans==-1)
            printf("Impossible.\n");
        else
            printf("Selected city (%d,%d) with minimum cost %d.\n",x0-1,y0-1,ans);
    }
    return(0);
}

