#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int S,T,tot,b[110],a[1000000][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[110],q[110];
bool build()
{
    int l,r;
    q[l=r=1]=S;
    memset(d,0,sizeof(d));
    d[S]=1;
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
int n,m,in[60],out[60],s[60],t[60],v[60][60],cnt[60][60];
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        scanf("%d%d",&n,&m);
        int s1=0,s2=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
            s1+=s[i];
        }
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&t[i]);
            s2+=t[i];
        }
        static int id=0;
        printf("Case %d:",++id);
        if (s1!=s2)
            printf(" impossible\n");
        else
        {
            S=n+m+1,T=S+1,tot=1;
            memset(b,0,sizeof(b));
            int ans=0;
            for (int i=1;i<=n;i++)
            {
                in[i]=tot+1;
                add(S,i,s[i]);
                ans+=s[i];
            }
            for (int i=1;i<=m;i++)
            {
                out[i]=tot+1;
                add(i+n,T,t[i]);
            }
            for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                {
                    cnt[i][j]=tot+1;
                    add(i,j+n,1);
                }
            while (build())
                ans-=dinic(S,inf);
            if (ans!=0)
                printf(" impossible\n");
            else
            {
                for (int i=1;i<=n;i++)
                    for (int j=1;j<=m;j++)
                    {
                        int x=cnt[i][j];
                        if (a[x][1]==1)
                        {
                            v[i][j]=0;
                            a[x][1]=0;
                            continue;
                        }
                        a[x^1][1]--;
                        a[in[i]][1]++;
                        a[in[i]^1][1]--;
                        a[out[j]][1]++;
                        a[out[j]^1][1]--;
                        if (build())
                        {
                            v[i][j]=0;
                            dinic(S,inf);
                        }
                        else
                        {
                            v[i][j]=1;
                            a[x][1]=1;
                            build();
                            dinic(S,inf);
                        }
                    }
                printf("\n");
                for (int i=1;i<=n;i++)
                {
                    for (int j=1;j<=m;j++)
                        printf("%d",v[i][j]);
                    printf("\n");
                }
            }
        }
    }
    return(0);
}

