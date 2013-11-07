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
edge a[10010];
int f[1010];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    for (int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].len);
    for (int i=1;i<=n;i++)
        f[i]=i;
    sort(a+1,a+m+1);
    int tot=0,ans=0;
    for (int i=1;i<=m;i++)
    {
        if (n-tot==K)
            break;
        int x=find(a[i].x),y=find(a[i].y);
        if (x==y)
            continue;
        ans+=a[i].len;
        tot++;
        f[x]=y;
    }
    if (n-tot==K)
        printf("%d\n",ans);
    else
        printf("No Answer\n");
    return(0);
}

