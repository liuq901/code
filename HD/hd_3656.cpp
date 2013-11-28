#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
};
point A[60];
struct data
{
    int l,r,u,d,y;
};
data a[2600];
int n,m,d[60][60];
vector <int> V;
inline int sqr(int x)
{
    return(x*x);
}
inline int dist(const point &a,const point &b)
{
    return(sqr(a.x-b.x)+sqr(a.y-b.y));
}
int p[60],sum[60];
void del(int x)
{
    for (int i=a[x].d;i!=x;i=a[i].d)
    {
        sum[a[i].y]--;
        a[a[i].l].r=a[i].r;
        a[a[i].r].l=a[i].l;
    }
}
void renew(int x)
{
    for (int i=a[x].u;i!=x;i=a[i].u)
    {
        sum[a[i].y]++;
        a[a[i].l].r=i;
        a[a[i].r].l=i;
    }
}
bool vis[60];
int best()
{
    memset(vis,0,sizeof(vis));
    int ans=0;
    for (int i=a[0].r;i!=0;i=a[i].r)
    {
        if (vis[i])
            continue;
        ans++;
        for (int j=a[i].d;j!=i;j=a[j].d)
            for (int k=a[j].r;k!=j;k=a[k].r)
                vis[a[k].y]=true;
    }
    return(ans);
}
bool DLX(int dep)
{
    if (a[0].r==0)
        return(true);
    if (dep+best()>m)
        return(false);
    int k,mi=1<<30;
    for (int i=a[0].r;i!=0;i=a[i].r)
        if (sum[i]<mi)
            mi=sum[k=i];
    for (int i=a[k].d;i!=k;i=a[i].d)
    {
        del(i);
        for (int j=a[i].r;j!=i;j=a[j].r)
            del(j);
        if (DLX(dep+1))
            return(true);
        for (int j=a[i].l;j!=i;j=a[j].l)
            renew(j);
        renew(i);
    }
    return(false);
}
bool check(int limit)
{
    for (int i=1;i<=n;i++)
        a[i].l=i-1,a[i].r=i+1,sum[i]=0,p[i]=i;
    a[0].l=n,a[0].r=1,a[n].r=0;
    int tot=n;
    for (int i=1;i<=n;i++)
    {
        int prev=tot+1;
        for (int j=1;j<=n;j++)
            if (d[i][j]<=limit)
            {
                tot++;
                a[tot].l=tot-1;
                a[tot].r=tot+1;
                a[tot].u=p[j];
                a[p[j]].d=tot;
                p[j]=tot;
                a[tot].y=j;
                sum[j]++;
            }
        a[tot].r=prev,a[prev].l=tot;
    }
    for (int i=1;i<=n;i++)
        a[p[i]].d=i,a[i].u=p[i];
    return(DLX(0));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&A[i].x,&A[i].y);
        V.clear();
        V.push_back(0);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                d[i][j]=dist(A[i],A[j]);
                V.push_back(d[i][j]);
            }
        sort(V.begin(),V.end());
        V.erase(unique(V.begin(),V.end()),V.end());
        int l=0,r=V.size()-1,ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(V[mid]))
                ans=V[mid],r=mid-1;
            else
                l=mid+1;
        }
        printf("%.6f\n",sqrt(double(ans)));
    }
    return(0);
}

