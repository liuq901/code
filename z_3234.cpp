#include <cstdio>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point
{
    int x,y;
    double angle;
    point(){}
    point(int x,int y):x(x),y(y){}
    void in()
    {
        scanf("%d%d",&x,&y);
    }
};
bool operator <(point a,point b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
point operator -(point a,point b)
{
    return(point(a.x-b.x,a.y-b.y));
}
ll operator *(point a,point b)
{
    return(ll(a.x)*b.y-ll(b.x)*a.y);
}
point a[2010];
bool cmp(point p,point q)
{
    return(p.angle<q.angle);
}
stack <point> s;
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
            a[i].in();
        int ans=0;
        while (n>2)
        {
            for (int i=1;i<=n;i++)
                if (a[i]<a[1])
                    swap(a[1],a[i]);
            for (int i=2;i<=n;i++)
                a[i].angle=atan2(a[i].y-a[1].y,a[i].x-a[1].x);
            sort(a+2,a+n+1,cmp);
            while (!s.empty())
                s.pop();
            s.push(a[1]);
            int m=0;
            for (int i=2;i<=n;i++)
            {
                while (s.size()>=2)
                {
                    point P=s.top();
                    s.pop();
                    point Q=s.top();
                    if ((P-Q)*(a[i]-P)>0)
                    {
                        s.push(P);
                        break;
                    }
                    else
                        a[++m]=P;
                }
                s.push(a[i]);
            }
            n=m;
            ans++;
        }
        printf("%d\n",ans);
    }
    return(0);
}

