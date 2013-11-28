#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
typedef map <int,int>::iterator iter;
const int N=100010,mod=1000000007,m=17;
bool vis[N];
int n,q[N],ans[N],b[N],a[2*N][3],fa[N][18];
vector <pair <int,int> > query[N];
void bfs()
{
    int l,r;
    memset(vis,0,sizeof(vis));
    q[l=r=1]=1;
    vis[1]=true;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (!vis[y])
            {
                vis[y]=true;
                q[++r]=y;
                fa[y][0]=x;
            }
        }
    }
}
int value[N],ch[N],pp[N],dep[N];
void init()
{
    dep[1]=1;
    for (int i=1;i<=n;i++)
    {
        int x=q[i];
        for (int j=b[x];j;j=a[j][2])
        {
            int y=a[j][0];
            if (y==fa[x][0])
                continue;
            dep[y]=dep[x]+1;
            ch[y]=a[j][1];
            value[y]=(value[x]*26LL+a[j][1])%mod;
        }
        for (int j=1;j<=m;j++)
            fa[x][j]=fa[fa[x][j-1]][j-1];
    }
    pp[0]=1;
    for (int i=1;i<=n;i++)
        pp[i]=pp[i-1]*26LL%mod;
}
int calc(int x,int p)
{
    return((value[x]-ll(value[p])*pp[dep[x]-dep[p]])%mod);
}
bool big(int x,int y)
{
    for (int i=m;i>=0;i--)
        if (dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    int x0=x,y0=y;
    for (int i=m;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    int p=fa[x][0];
    x=x0,y=y0;
    for (int i=m;i>=0;i--)
        if (calc(fa[x][i],p)!=calc(fa[y][i],p))
            x=fa[x][i],y=fa[y][i];
    return(ch[x]>=ch[y]);
}
void merge(map <int,int> &s1,map <int,int> &s2)
{
    for (iter k=s1.begin();k!=s1.end();k++)
    {
        iter t=s2.lower_bound(k->first);
        if (t!=s2.end() && big(t->second,k->second))
            continue;
        while (1)
        {
            t=s2.upper_bound(k->first);
            if (t!=s2.begin() && big(k->second,(--t)->second))
                s2.erase(t);
            else
                break;
        }
        s2.insert(*k);
    }
}
map <int,int> M[N];
int c[N];
inline int ancester(int x,int p)
{
    for (int i=0;i<=m;i++)
        if (p>>i&1)
            x=fa[x][i];
    return(x);
}
void work()
{
    for (int i=1;i<=n;i++)
    {
        M[i].clear();
        c[i]=i;
    }
    for (int i=n;i;i--)
    {
        int x=q[i];
        for (int j=b[x];j;j=a[j][2])
        {
            int y=a[j][0];
            if (y==fa[x][0])
                continue;
            if (M[c[x]].size()<M[c[y]].size())
            {
                merge(M[c[x]],M[c[y]]);
                c[x]=c[y];
            }
            else
                merge(M[c[y]],M[c[x]]);
        }
        M[c[x]].insert(make_pair(dep[x],x));
        for (int j=0;j<query[x].size();j++)
        {
            int u=query[x][j].first,id=query[x][j].second;
            iter k=M[c[x]].lower_bound(dep[x]+u);
            if (k==M[c[x]].end())
                ans[id]=-1;
            else
            {
                int v=k->second;
                v=ancester(v,dep[v]-dep[x]-u);
                ans[id]=(value[v]-ll(value[x])*pp[u])%mod;
                if (ans[id]<0)
                    ans[id]+=mod;
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y;
            char ch;
            scanf("%d%d %c",&x,&y,&ch);
            a[i][0]=y,a[i][1]=ch-'a',a[i][2]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=ch-'a',a[i+n][2]=b[y],b[y]=i+n;
        }
        for (int i=1;i<=n;i++)
            query[i].clear();
        int Q;
        scanf("%d",&Q);
        for (int i=1;i<=Q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            query[x].push_back(make_pair(y,i));
        }
        bfs();
        init();
        work();
        for (int i=1;i<=Q;i++)
        {
            if (ans[i]==-1)
                printf("IMPOSSIBLE\n");
            else
                printf("%d\n",ans[i]);
        }
    }
    return(0);
}

