#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
    int x,y,len;
};
inline bool operator <(const edge &a,const edge &b)
{
    return(a.len<b.len || a.len==b.len && a.y<b.y);
}
int f[10010];
edge e[110010];
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
        int n,m,A;
        scanf("%d%d%d",&n,&m,&A);
        for (int i=1;i<=m;i++)
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].len);
        for (int i=1;i<=n;i++)
        {
            e[i+m].x=i;
            e[i+m].y=0;
            e[i+m].len=A;
        }
        for (int i=0;i<=n;i++)
            f[i]=i;
        sort(e+1,e+n+m+1);
        int ans=0,cnt=0;
        for (int i=1;i<=n+m;i++)
        {
            int x=find(e[i].x),y=find(e[i].y);
            if (x==y)
                continue;
            ans+=e[i].len;
            cnt+=e[i].y==0;
            f[x]=y;
        }
        static int id=0;
        printf("Case %d: %d %d\n",++id,ans,cnt);
    }
    return(0);
}

