#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct edge
{
    int x,y,g,s;
};
inline bool cmpG(const edge &a,const edge &b)
{
    return(a.g<b.g);
}
inline bool cmpS(const edge &a,const edge &b)
{
    return(a.s<b.s);
}
edge tmp[210],now[210],e[50010];
int f[210];
void clear(int n)
{
    for (int i=1;i<=n;i++)
        f[i]=i;
}
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
ll kruskal(int n,int m,int G,int S,edge *e)
{
    clear(n);
    int tot=0,g=0,s=0;
    for (int i=1;i<=m;i++)
    {
        int x=e[i].x,y=e[i].y;
        if (find(x)==find(y))
            continue;
        f[find(x)]=find(y);
        g=max(g,e[i].g);
        s=max(s,e[i].s);
        now[++tot]=e[i];
    }
    if (tot!=n-1)
        return(-1);
    return(ll(g)*G+ll(s)*S);
}
int main()
{
    int n,m,G,S;
    scanf("%d%d%d%d",&n,&m,&G,&S);
    for (int i=1;i<=m;i++)
        scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].g,&e[i].s);
    sort(e+1,e+m+1,cmpG);
    ll ans=kruskal(n,m,G,S,e);
    if (ans==-1)
        printf("-1\n");
    else
    {
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<n;j++)
                tmp[j]=now[j];
            tmp[n]=e[i];
            sort(tmp+1,tmp+n+1,cmpS);
            ans=min(ans,kruskal(n,n,G,S,tmp));
        }
        printf("%I64d\n",ans);
    }
    return(0);
}

