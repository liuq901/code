#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
const double eps=1e-8;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
point operator -(point a,point b)
{
    return(point(a.x-b.x,a.y-b.y));
}
double operator *(point a,point b)
{
    return(a.x*b.y-a.y*b.x);
}
bool operator ==(point a,point b)
{
    return(fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps);
}
point a[1010];
vector <point> poly;
double dist(point p,point q)
{
    return(sqrt(SQR(p.x-q.x)+SQR(p.y-q.y)));
}
bool cmp(point p,point q)
{
    double a1=atan2(p.y-a[1].y,p.x-a[1].x),a2=atan2(q.y-a[1].y,q.x-a[1].x);
    double d1=dist(p,a[1]),d2=dist(q,a[1]);
    return(a1<a2 || fabs(a1-a2)<eps && d1<d2);
}
double dot(point a,point b)
{
    return(a.x*b.x+a.y*b.y);
}
bool online(point P,point A,point B)
{
    return(fabs((A-P)*(B-P))<eps && dot(A-P,B-P)<0);
}
bool f[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for (int i=2;i<=n;i++)
            if (a[i].x<a[1].x || fabs(a[1].x-a[i].x)<eps && a[i].y<a[1].y)
                swap(a[1],a[i]);
        sort(a+2,a+n+1,cmp);
        poly.clear();
        poly.push_back(a[1]);
        for (int i=2;i<=n;i++)
        {
            while (poly.size()>=2)
            {
                point P=poly[poly.size()-1],Q=poly[poly.size()-2];
                if ((P-Q)*(a[i]-P)<eps)
                    poly.pop_back();
                else
                    break;
            }
            poly.push_back(a[i]);
        }
        if (poly.size()<=2)
        {
            printf("NO\n");
            continue;
        }
        poly.push_back(a[1]);
        memset(f,0,sizeof(f));
        for (int i=0;i<poly.size()-1;i++)
            for (int j=1;j<=n;j++)
            {
                if (a[j]==poly[i] || a[j]==poly[i+1])
                    continue;
                if (online(a[j],poly[i],poly[i+1]))
                {
                    f[i]=true;
                    break;
                }
            }
        bool flag=true;
        for (int i=0;i<poly.size()-1;i++)
            if (!f[i])
            {
                flag=false;
                break;
            }
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

