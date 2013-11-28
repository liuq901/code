#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
    int x,y;
    double len;
};
inline bool operator <(const edge &a,const edge &b)
{
    return(a.len<b.len);
}
edge a[100010];
int f[100010];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int n;
    double tot;
    scanf("%lf%d",&tot,&n);
    for (int i=1;i<=n;i++)
        f[i]=i;
    int m=1;
    while (scanf("%d%d%lf",&a[m].x,&a[m].y,&a[m].len)==3)
        m++;
    m--;
    sort(a+1,a+m+1);
    double ans=0;
    int sum=0;
    for (int i=1;i<=m;i++)
    {
        int x=find(a[i].x),y=find(a[i].y);
        if (x==y)
            continue;
        sum++;
        ans+=a[i].len;
        f[x]=y;
    }
    if (ans<=tot && sum==n-1)
        printf("Need %.2f miles of cable\n",ans);
    else
        printf("Impossible\n");
    return(0);
}

