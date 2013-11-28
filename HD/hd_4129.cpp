#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf=1LL<<60;
struct point
{
    int x,y;
};
inline ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
point p[1010];
int tot,N,b[2010],e[10010][3],to[20010],a[1000000][2];
bool vis[20010];
ll capa[2010];
void farmland(int n,int P)
{
    for (int i=1;i<=n;i++)
    {
        vector <pair <double,int> > lq;
        for (int j=b[i];j;j=a[j][1])
        {
            int x=a[j][0];
            lq.push_back(make_pair(atan2(p[x].y-p[i].y,p[x].x-p[i].x),j));
        }
        sort(lq.begin(),lq.end());
        for (int j=0;j<lq.size();j++)
            to[lq[(j+1)%lq.size()].second^1]=lq[j].second;
    }
    memset(vis,0,sizeof(vis));
    N=0;
    for (int i=2;i<=tot;i++)
        if (!vis[i])
        {
            ll area=0;
            vector <int> lq;
            for (int j=i;!vis[j];j=to[j])
            {
                area+=det(p[a[j^1][0]],p[a[j][0]]);
                vis[j]=true;
                lq.push_back(j);
            }
            if (area>0)
            {
                capa[++N]=area*P/2;
                for (int j=0;j<lq.size();j++)
                {
                    int x=lq[j];
                    if (x&1)
                        e[x/2][0]=N;
                    else
                        e[x/2][1]=N;
                }
            }
        }
}
int SS,TT,S,T;
ll v[1000000];
void add(int x,int y,ll c)
{
    a[++tot][0]=y,a[tot][1]=b[x],v[tot]=c,b[x]=tot;
    a[++tot][0]=x,a[tot][1]=b[y],v[tot]=0,b[y]=tot;
}
void add(int x,int y,ll l,ll r)
{
    if (l!=0)
    {
        add(S,y,l);
        add(x,T,l);
    }
    add(x,y,r-l);
}
int d[2010],q[2010];
bool build()
{
    memset(d,0,sizeof(d));
    int l,r;
    q[l=r=1]=S;
    d[S]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (d[y] || !v[i])
                continue;
            d[y]=d[x]+1;
            q[++r]=y;
            if (y==T)
                return(true);
        }
    }
    return(false);
}
ll dinic(int x,ll flow)
{
    if (x==T)
        return(flow);
    ll k=flow;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (d[y]!=d[x]+1 || !v[i])
            continue;
        ll t=dinic(y,min(k,v[i]));
        k-=t;
        v[i]-=t;
        v[i^1]+=t;
        if (k==0)
            break;
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
int main()
{
    while (1)
    {
        int n,m,mi,ma,P;
        scanf("%d%d%d%d%d",&n,&m,&mi,&ma,&P);
        if (n==0 && m==0 && mi==0 && ma==0 && P==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d%d",&x,&y,&e[i][2]);
            x++,y++;
            a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
            a[++tot][0]=x,a[tot][1]=b[y],b[y]=tot;
        }
        farmland(n,P);
        tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            add(e[i][0],e[i][1],0,e[i][2]);
            add(e[i][1],e[i][0],0,e[i][2]);
        }
        SS=N+1,TT=SS+1,S=TT+1,T=S+1;
        for (int i=1;i<=N;i++)
        {
            add(SS,i,0,capa[i]);
            add(i,TT,mi,ma);
        }
        add(TT,SS,inf);
        ll ans=0;
        while (build())
            ans+=dinic(S,inf);
        if (ans!=ll(N)*mi)
            printf("-1\n");
        else
        {
            v[tot-1]=v[tot]=0;
            S=SS,T=TT;
            while (build())
                ans+=dinic(S,inf);
            printf("%I64d\n",ans);
        }
    }
    return(0);
}

