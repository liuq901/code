#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int inf=1<<30;
string s[10010];
char buf[1000000];
int tot=1,S,T,pre[10010],suf[10010],b[10010],a[1000010][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
void init(int n,int K)
{
    map <string,int> M;
    int m=0;
    for (int i=1;i<=n;i++)
    {
        string now=s[i].substr(0,K);
        if (!M.count(now))
        {
            M[now]=++m;
            add(S,m,1);
        }
        pre[i]=M[now];
    }
    M.clear();
    for (int i=1;i<=n;i++)
    {
        string now=s[i].substr(s[i].size()-K);
        if (!M.count(now))
        {
            M[now]=++m;
            add(m,T,1);
        }
        suf[i]=M[now];
    }
    for (int i=1;i<=n;i++)
        add(pre[i],suf[i],inf);
}
int d[10010],q[10010];
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
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
int c[10010];
vector <int> ans[10010];
int hash(int x)
{
    if (c[x]==0)
        c[x]=++tot;
    return(c[x]);
}
void print(int n)
{
    tot=0;
    for (int i=1;i<=n;i++)
    {
        int x=pre[i];
        if (d[x]==0)
            ans[hash(x)].push_back(i);
        else
            ans[hash(suf[i])].push_back(i);
    }
    for (int i=1;i<=tot;i++)
    {
        printf("%d",ans[i].size());
        for (int j=0;j<ans[i].size();j++)
            printf(" %d",ans[i][j]);
        printf("\n");
    }
}
int main()
{
    freopen("heavy.in","r",stdin);
    freopen("heavy.out","w",stdout);
    int n,K;
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",buf);
        s[i]=buf;
    }
    S=2*n+1,T=S+1;
    init(n,K);
    int ans=0;
    while (build())
        ans+=dinic(S,inf);
    printf("%d\n",ans);
    print(n);
    return(0);
}

