#include <cstdio>
#include <algorithm>
using namespace std;
const int N=510;
struct edge
{
    int x,y,z;
};
inline bool operator <(const edge &a,const edge &b)
{
    return(a.z<b.z);
}
edge a[N*N];
bool use[N*N];
int n,m,f[N];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int kruskal(int id)
{
    for (int i=1;i<=n;i++)
        f[i]=i;
    int tot=0,ret=0;
    for (int i=1;i<=m;i++)
    {
        int x=find(a[i].x),y=find(a[i].y);
        if (x==y || id==i)
            continue;
        f[x]=y;
        tot++;
        ret+=a[i].z;
        if (id==0)
            use[i]=true;
    }
    if (tot!=n-1)
        return(1<<30);
    return(ret);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    sort(a+1,a+m+1);
    int ans0=kruskal(0),ans1=1<<30;
    for (int i=1;i<=m;i++)
        if (use[i])
            ans1=min(ans1,kruskal(i));
    if (ans1==1<<30)
        ans1=-1;
    printf("Cost: %d\nCost: %d\n",ans0,ans1);
    return(0);
}

