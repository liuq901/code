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
edge e[500010];
int f[10010],s[10010],a[10010],sum[10010];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            e[i].x=x+1,e[i].y=y+1,e[i].len=z;
        }
        sort(e+1,e+m+1);
        for (int i=1;i<=n;i++)
        {
            f[i]=i;
            s[i]=1;
        }
        int tot=0;
        for (int i=1;i<=m;i++)
        {
            int x=find(e[i].x),y=find(e[i].y);
            if (x==y)
                continue;
            a[++tot]=e[i].len;
            sum[tot]=s[x]*s[y];
            f[x]=y;
            s[y]+=s[x];
        }
        for (int i=1;i<=tot;i++)
            sum[i]+=sum[i-1];
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int x;
            scanf("%d",&x);
            int id=lower_bound(a+1,a+tot+1,x)-a;
            printf("%d\n",(sum[tot]-sum[id-1])*2);
        }
    }
    return(0);
}

