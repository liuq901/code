#include <cstdio>
#include <string>
#include <map>
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
edge e[60];
int f[110];
map <string,int> M;
int hash(const string &s)
{
    if (!M.count(s))
    {
        int tmp=M.size()+1;
        M[s]=tmp;
    }
    return(M[s]);
}
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
        if (x!=y)
        {
            f[x]=y;
            ret+=e[i].len;
        }
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
        int m;
        scanf("%d",&m);
        M.clear();
        for (int i=1;i<=m;i++)
        {
            char a[60],b[60];
            scanf("%s%s%d",a,b,&e[i].len);
            e[i].x=hash(a);
            e[i].y=hash(b);
        }
        static int id=0;
        printf("Case %d: ",++id);
        int ans=kruskal(M.size(),m);
        if (ans==-1)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

