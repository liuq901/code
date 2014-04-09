#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
    int x,y,len;
    edge(){}
    edge(int x,int y,int len):x(x),y(y),len(len){}
};
inline bool operator <(const edge &a,const edge &b)
{
    return(a.len<b.len);
}
edge e[2510];
int f[60];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int kruskal(int n,int m)
{
    for (int i=1;i<=n;i++)
        f[i]=i;
    sort(e+1,e+m+1);
    int ret=0;
    for (int i=1;i<=m;i++)
    {
        int x=find(e[i].x),y=find(e[i].y);
        if (x==y)
            ret+=e[i].len;
        else
            f[x]=y;
    }
    for (int i=1;i<=n;i++)
        if (find(i)!=find(1))
            return(-1);
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                int x;
                scanf("%d",&x);
                if (x)
                    e[++m]=edge(i,j,x);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,kruskal(n,m));
    }
    return(0);
}

