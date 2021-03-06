#include <cstdio>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
char buf[1000000];
int n,m,tot,S,T,b[2010],a[1000000][3];
vector <int> to[2010];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
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
    if (flow==k)
        d[x]=-1;
    return(flow-k);
}
bool check(int mid)
{
    tot=1;
    memset(b,0,sizeof(b));
    for (int i=1;i<=n;i++)
    {
        add(S,i,1);
        for (int j=0;j<to[i].size();j++)
            add(i,to[i][j]+n,1);
    }
    for (int i=1;i<=m;i++)
        add(i+n,T,mid);
    int ans=n;
    while (build())
        ans-=dinic(S,1<<30);
    return(ans==0);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        gets(buf);
        S=n+m+1,T=S+1;
        for (int i=1;i<=n;i++)
        {
            to[i].clear();
            gets(buf);
            stringstream sin(buf);
            sin>>buf;
            int x;
            while (sin>>x)
                to[i].push_back(x+1);
        }
        int l=1,r=n,ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(mid))
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return(0);
}

