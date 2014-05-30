#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int tot,S,T,cost,pre[130],p[130],d[130],b[130],a[1000000][4];
bool in[130];
void add(int x,int y,int z,int c)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=c,a[tot][3]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-c,a[tot][3]=b[y],b[y]=tot;
}
bool spfa()
{
    memset(d,63,sizeof(d));
    d[S]=0;
    queue <int> Q;
    Q.push(S);
    in[S]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
        for (int i=b[x];i;i=a[i][3])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+a[i][2]<d[y])
            {
                d[y]=d[x]+a[i][2];
                pre[y]=x;
                p[y]=i;
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
        }
    }
    if (d[T]==d[0])
        return(false);
    cost+=d[T];
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        a[x][1]--;
        a[x^1][1]++;
    }
    return(true);
}
char s[40][40];
int f[40][40],cnt[40][40],q[910][2];
void bfs(int Sx,int Sy)
{
    int l,r;
    q[l=r=1][0]=Sx,q[1][1]=Sy;
    memset(f,63,sizeof(f));
    f[Sx][Sy]=0;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (f[x0][y0]+1<f[x][y] && s[x][y]!='#')
            {
                f[x][y]=f[x0][y0]+1;
                q[++r][0]=x,q[r][1]=y;
            }
        }
    }
}
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n,K;
        scanf("%d%d%*d",&n,&K);
        for (int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        int t=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (s[i][j]=='m')
                    cnt[i][j]=++t;
        S=K+t+1,T=S+1,tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=K;i++)
        {
            int x;
            scanf("%d",&x);
            add(S,i+t,x,0);
        }
        for (int i=1;i<=t;i++)
            add(i,T,1,0);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (isupper(s[i][j]))
                {
                    bfs(i,j);
                    int p=s[i][j]-'A'+1;
                    for (int x=1;x<=n;x++)
                        for (int y=1;y<=n;y++)
                            if (s[x][y]=='m')
                                add(p+t,cnt[x][y],1,f[x][y]);
                }
        cost=0;
        while (spfa());
        static int id=0;
        printf("Case %d: %d\n",++id,cost);
    }
    return(0);
}

