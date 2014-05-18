#include <cstdio>
#include <vector>
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
vector <edge> e;
int f[210];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int kruskal(int n)
{
    sort(e.begin(),e.end());
    int ret=0,cnt=0;
    for (int i=1;i<=n;i++)
        f[i]=i;
    for (int i=0;i<e.size();i++)
    {
        int x=find(e[i].x),y=find(e[i].y);
        if (x==y)
            continue;
        ret+=e[i].len;
        f[x]=y;
        e[cnt++]=e[i];
    }
    e.resize(cnt);
    return(cnt==n-1?ret:-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        e.clear();
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=m;i++)
        {
            int x,y,len;
            scanf("%d%d%d",&x,&y,&len);
            e.push_back(edge(x,y,len));
            printf("%d\n",kruskal(n));
        }
    }
    return(0);
}

