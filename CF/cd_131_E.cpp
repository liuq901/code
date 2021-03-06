#include <cstdio>
#include <set>
using namespace std;
set <pair <int,int> > a[100010],b[100010],c[200010],d[200010];
pair <int,int> p[100010];
int ans[10];
int calc(const pair <int,int> p,const set <pair <int,int> > &a)
{
    int x=p.first,y=p.second,ret=0;
    if (*a.begin()!=p)
        ret++;
    if (a.upper_bound(p)!=a.end())
        ret++;
    return(ret);
}
int main()
{
    int n;
    scanf("%*d%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]=make_pair(x,y);
        a[x].insert(p[i]);
        b[y].insert(p[i]);
        c[x+y].insert(p[i]);
        d[x-y+100000].insert(p[i]);
    }
    for (int i=1;i<=n;i++)
    {
        int sum=0,x=p[i].first,y=p[i].second;
        sum=calc(p[i],a[x])+calc(p[i],b[y])+calc(p[i],c[x+y])+calc(p[i],d[x-y+100000]);
        ans[sum]++;
    }
    for (int i=0;i<=8;i++)
        printf("%d%c",ans[i],i==8?'\n':' ');
    return(0);
}

