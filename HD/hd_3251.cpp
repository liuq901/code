#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=1<<30;
int S,T,tot,b[1010],d[1010],q[1010],e[100010][2],a[500010][3];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
bool build()
{
    int l,r;
    memset(d,0,sizeof(d));
    d[S]=1;
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
        if (!k)
            break;
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
vector <int> s;
int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        memset(b,0,sizeof(b));
        tot=1;
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
            e[i][0]=x,e[i][1]=y;
        }
        ll ans=0;
        S=1,T=0;
        for (int i=1;i<=K;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,T,y);
            ans+=y;
        }
        while (build())
            ans-=dinic(S,inf);
        s.clear();
        for (int i=1;i<=m;i++)
        {
            int x=e[i][0],y=e[i][1];
            if (d[x]!=0 && d[y]==0)
                s.push_back(i);
        }
        static int id=0;
        printf("Case %d: %I64d\n",++id,ans);
        printf("%d",s.size());
        for (int i=0;i<s.size();i++)
            printf(" %d",s[i]);
        printf("\n");
    }
    return(0);
}

