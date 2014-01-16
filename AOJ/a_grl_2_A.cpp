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
int f[10010];
edge e[100010];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].len);
        e[i].x++,e[i].y++;
    }
    for (int i=1;i<=n;i++)
        f[i]=i;
    sort(e+1,e+m+1);
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int x=find(e[i].x),y=find(e[i].y);
        if (x==y)
            continue;
        f[x]=y;
        ans+=e[i].len;
    }
    printf("%d\n",ans);
    return(0);
}

