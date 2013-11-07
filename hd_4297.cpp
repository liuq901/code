#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
const int N=500010;
int n,vis[N],Circle,to[N],circle_cnt[N],dep[N],q[N],tree[N],fa[N][20];
pair <int,int> circle[N];
vector <int> son[N];
void findCircle()
{
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (vis[i])
            continue;
        cnt++;
        for (int j=i;;j=to[j])
        {
            vis[j]=cnt;
            if (vis[to[j]])
            {
                if (vis[to[j]]==cnt)
                {
                    int tot=1;
                    circle[to[j]]=make_pair(++Circle,tot);
                    for (int k=to[to[j]];k!=to[j];k=to[k])
                        circle[k]=make_pair(Circle,++tot);
                    circle_cnt[Circle]=tot;
                }
                break;
            }
        }
    }
}
void BFS()
{
    for (int i=1;i<=n;i++)
        if (!circle[i].first)
            son[to[i]].push_back(i);
    for (int i=1;i<=n;i++)
        if (circle[i].first)
        {
            int l,r;
            q[l=r=1]=i;
            dep[i]=0;
            while (l<=r)
            {
                int x=q[l++];
                tree[x]=i;
                for (int j=0;j<son[x].size();j++)
                {
                    int y=son[x][j];
                    fa[y][0]=x;
                    dep[y]=dep[x]+1;
                    q[++r]=y;
                }
            }
            for (int j=0;j<20;j++)
                fa[i][j]=0;
            for (int j=2;j<=r;j++)
            {
                int x=q[j];
                for (int k=1;k<20;k++)
                    fa[x][k]=fa[fa[x][k-1]][k-1];
            }
        }
}
int LCA(int x,int y)
{
    if (dep[x]<dep[y])
        swap(x,y);
    int t=dep[x]-dep[y];
    for (int i=19;i>=0;i--)
        if (t>=(1<<i))
        {
            x=fa[x][i];
            t-=1<<i;
        }
    if (x==y)
        return(x);
    for (int i=19;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return(fa[x][0]);
}
int len(int x,int y)
{
    int ret=circle[y].second-circle[x].second;
    if (ret<0)
        ret+=circle_cnt[circle[y].first];
    return(ret);
}
pair <int,int> get(pair <int,int> x,pair <int,int> y)
{
    int A1=x.first,B1=x.second,A2=y.first,B2=y.second;
    if (max(A1,B1)!=max(A2,B2))
        return(max(A1,B1)<max(A2,B2)?x:y);
    if (min(A1,B1)!=min(A2,B2))
        return(min(A1,B1)<min(A2,B2)?x:y);
    return(B1<B2?x:y);
}
void getans(int x,int y)
{
    int u=tree[x],v=tree[y];
    if (circle[u].first!=circle[v].first)
        printf("-1 -1\n");
    else if (u==v)
    {
        int t=LCA(x,y);
        printf("%d %d\n",dep[x]-dep[t],dep[y]-dep[t]);
    }
    else
    {
        int A=dep[x],B=dep[y];
        pair <int,int> ans=get(make_pair(A+len(u,v),B),make_pair(A,B+len(v,u)));
        printf("%d %d\n",ans.first,ans.second);
    }
}
int main()
{
    int Q;
    while (scanf("%d%d",&n,&Q)==2)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&to[i]);
            circle[i]=make_pair(0,0);
            son[i].clear();
        }
        memset(vis,0,sizeof(vis));
        Circle=0;
        findCircle();
        BFS();
        while (Q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            getans(x,y);
        }
    }
    return(0);
}

