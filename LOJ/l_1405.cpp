#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int S,T,tot,b[20010],a[1000000][3];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[20010],q[20010];
bool build()
{
    memset(d,0,sizeof(d));
    d[S]=1;
    int l,r;
    q[l=r=1]=S;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y] || !a[i][1])
                continue;
            d[y]=d[x]+1;
            q[++r]=y;
            if (y==T)
                return(true);
        }
    }
    return(false);
}
int dinic(int x,int flow)
{
    if (x==T)
        return(flow);
    int k=flow;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (d[y]!=d[x]+1 || !a[i][1])
            continue;
        int t=dinic(y,min(k,a[i][1]));
        k-=t;
        a[i][1]-=t;
        a[i^1][1]+=t;
        if (k==0)
            break;
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
char s[110][110];
int cnt[110][110];
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int R,C;
        scanf("%d%d",&R,&C);
        for (int i=1;i<=R;i++)
            scanf("%s",s[i]+1);
        int n=0;
        for (int i=1;i<=R;i++)
            for (int j=1;j<=C;j++)
                cnt[i][j]=++n;
        S=2*n+1,T=S+1,tot=1;
        memset(b,0,sizeof(b));
        int ans=0;
        for (int i=1;i<=R;i++)
            for (int j=1;j<=C;j++)
            {
                add(cnt[i][j],cnt[i][j]+n,1);
                if (s[i][j]=='*')
                {
                    add(S,cnt[i][j],1);
                    ans++;
                }
                if (i==1 || i==R || j==1 || j==C)
                    add(cnt[i][j]+n,T,1);
                for (int k=0;k<4;k++)
                {
                    int x=i+c[k][0],y=j+c[k][1];
                    if (x>=1 && x<=R && y>=1 && y<=C)
                        add(cnt[i][j]+n,cnt[x][y],1);
                }
            }
        while (build())
            ans-=dinic(S,1<<30);
        static int id=0;
        printf("Case %d: %s\n",++id,ans?"no":"yes");
    }
    return(0);
}

