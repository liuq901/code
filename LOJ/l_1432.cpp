#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline bool operator ==(const point &a,const point &b)
{
    return(a.x==b.x && a.y==b.y);
}
inline ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
struct event
{
    point p;
    int delta;
    event(const point &p,int delta):p(p),delta(delta){}
};
inline bool operator <(const event &a,const event &b)
{
    return(a.p<b.p || a.p==b.p && a.delta<b.delta);
}
point a[100010],b[100010];
int c[100010];
inline bool cmp(int x,int y)
{
    return(det(b[x]-a[x],b[y]-a[y])>0 || det(b[x]-a[x],b[y]-a[y])==0 && det(b[x]-a[x],b[y]-a[x])>0);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
            if (b[i]<a[i])
                swap(a[i],b[i]);
            c[i]=i;
        }
        sort(c+1,c+n+1,cmp);
        ll ans=0;
        for (int i=1,j;i<=n;i=j)
        {
            vector <event> e;
            for (j=i;j<=n && det(b[c[i]]-a[c[i]],b[c[j]]-a[c[j]])==0 && det(b[c[i]]-a[c[i]],b[c[j]]-a[c[i]])==0;j++)
            {
                e.push_back(event(a[c[j]],1));
                e.push_back(event(b[c[j]],-1));
            }
            sort(e.begin(),e.end());
            int cnt=0;
            for (int i=0;i<e.size();i++)
            {
                if (e[i].delta==-1)
                    ans+=cnt-1;
                cnt+=e[i].delta;
            }
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

