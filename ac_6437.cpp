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
int b[210],p[210],f[210];
edge e[1000000];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=K;i++)
            scanf("%d",&p[i]);
        for (int i=1;i<=m;i++)
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].len);
        for (int i=1;i<=n;i++)
            f[i]=i;
        for (int i=2;i<=K;i++)
            f[find(p[i])]=find(p[1]);
        sort(e+1,e+m+1);
        int ans=0;
        for (int i=1;i<=m;i++)
        {
            int x=e[i].x,y=e[i].y;
            if (find(x)==find(y))
                continue;
            ans+=e[i].len;
            f[find(x)]=find(y);
        }
        static int id=0;
        printf("Case #%d: %d\n",++id,ans);
    }
    return(0);
}

