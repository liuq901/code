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
edge e[12010];
int f[110];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int kruskal(int n,int m)
{
    sort(e+1,e+m+1);
    for (int i=0;i<=n;i++)
        f[i]=i;
    int ret=0;
    for (int i=1;i<=m;i++)
    {
        int x=find(e[i].x),y=find(e[i].y);
        if (x==y)
            continue;
        ret+=e[i].len;
        f[x]=y;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int m=0;
        while (1)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if (x==0 && y==0 && z==0)
                break;
            e[++m].x=x,e[m].y=y,e[m].len=z;
        }
        int ans1=kruskal(n,m);
        for (int i=1;i<=m;i++)
            e[i].len*=-1;
        int ans2=-kruskal(n,m);
        static int id=0;
        printf("Case %d: ",++id);
        if (ans1+ans2&1)
            printf("%d/2\n",ans1+ans2);
        else
            printf("%d\n",ans1+ans2>>1);
    }
    return(0);
}

