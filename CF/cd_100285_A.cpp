#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
};
inline bool operator <(const point &a,const point &b)
{
    return(a.y<b.y || a.y==b.y && a.x<b.x);
}
double calc(point *a,int t,int y)
{
    if (a[t].y==y)
        return(a[t].x);
    double x0=a[t-1].x,y0=a[t-1].y,x1=a[t].x,y1=a[t].y;
    return((y-y0)*(x1-x0)/(y1-y0)+x0);
}
point a[100010],b[100010],p[100010];
vector <int> Y;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        Y.push_back(a[i].y);
    }
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&b[i].x,&b[i].y);
        Y.push_back(b[i].y);
    }
    int K,ymin=a[1].y,ymax=a[n].y;
    scanf("%d",&K);
    for (int i=1;i<=K;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        if (p[i].y<ymin || p[i].y>ymax)
            K--,i--;
        else
            Y.push_back(p[i].y);
    }
    sort(p+1,p+K+1);
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    int u=1,v=1,w=1;
    double ans=1e100;
    for (int i=0;i<Y.size();i++)
    {
        int y=Y[i];
        while (a[u].y<y)
            u++;
        double xmin=calc(a,u,y);
        while (b[v].y<y)
            v++;
        double xmax=calc(b,v,y),prev=xmin,now=0;
        while (w<=K && p[w].y==y)
        {
            double x=p[w].x;
            if (x>=xmin && x<=xmax)
            {
                now=max(now,x-prev);
                prev=x;
            }
            w++;
        }
        now=max(now,xmax-prev);
        ans=min(ans,now);
    }
    printf("%.10f\n",ans);
    return(0);
}

