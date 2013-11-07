#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
    int x,y,len;
};
inline bool operator <(const edge &a,const edge &b)
{
    return(a.len<b.len);
}
edge a[1000000];
bool vis[1000000];
int n,m,f[510];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int ans0,ans1=1<<30;
int kruskal(int id)
{
    for (int i=1;i<=n;i++)
        f[i]=i;
    int tot=0,ret=0;
    for (int i=1;i<=m;i++)
    {
        int x=find(a[i].x),y=find(a[i].y);
        if (x==y || i==id)
            continue;
        if (id==0)
            vis[i]=true;
        f[x]=y;
        tot++;
        ret+=a[i].len;
        if (ret>=ans1)
            return(ret);
    }
    if (tot!=n-1)
        ret=1<<30;
    return(ret);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].len);
    sort(a+1,a+m+1);
    ans0=kruskal(0);
    for (int i=1;i<=m;i++)
        if (vis[i])
            ans1=min(ans1,kruskal(i));
    if (ans0==1<<30)
        ans0=-1;
    if (ans1==1<<30)
        ans1=-1;
    printf("Cost: %d\nCost: %d\n",ans0,ans1);
    return(0);
}

