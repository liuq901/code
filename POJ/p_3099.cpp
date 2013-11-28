#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct point
{
    int x,y,z;
    void in()
    {
        scanf("%d%d%d",&x,&y,&z);
    }
};
int tot,id[1010],b[1010],dep[1010],f[1010],a[2010][2];
point p[1010];
inline int sqr(int x)
{
    return(x*x);
}
inline int dist(const point &a,const point &b)
{
    return(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z));
}
inline void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=b[y],b[y]=tot;
}
void dfs(int x,int father)
{
    dep[x]=dep[father]+1;
    f[x]=father;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dfs(y,x);
    }
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&id[i]);
            p[i].in();
        }
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=2;i<=n;i++)
        {
            int k=1;
            for (int j=1;j<i;j++)
                if (dist(p[i],p[j])<dist(p[i],p[k]))
                    k=j;
            add(k,i);
        }
        dfs(1,0);
        int k=1;
        for (int i=1;i<=n;i++)
            if (dep[i]>dep[k])
                k=i;
        dfs(k,0);
        k=1;
        for (int i=1;i<=n;i++)
            if (dep[i]>dep[k])
                k=i;
        int p=dep[k]-1>>1,x=k,y;
        for (int i=1;i<=p;i++)
            x=f[x];
        if (dep[k]&1)
            printf("%d\n",id[x]);
        else
        {
            y=f[x];
            printf("%d %d\n",min(id[x],id[y]),max(id[x],id[y]));
        }
    }
    return(0);
}

