#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
};
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || sign(a.x-b.x)==0 && sign(a.y-b.y)<0);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
point a[100010];
int ys[100010],tmp[100010];
inline bool ystmp(int v1,int v2)
{
    return(sign(a[v1].y-a[v2].y)<0);
}
double minimal(point *c,int n,int *ys)
{
    double ret=1e100;
    if (n<20)
    {
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
            {
                if (sign(dist(c[i],c[j])-ret)<0)
                    ret=dist(c[i],c[j]);
                if (sign(a[ys[i]].y-a[ys[j]].y)>0)
                    swap(ys[i],ys[j]);
            }
        return(ret);
    }
    int mid=n/2,cnt=0;
    double xmid=c[mid].x;
    ret=min(minimal(c,mid,ys),minimal(c+mid,n-mid,ys+mid));
    merge(ys,ys+mid,ys+mid,ys+n,tmp,ystmp);
    copy(tmp,tmp+n,ys);
    for (int i=0;i<n;i++)
    {
        while (i<n && sign(fabs(a[ys[i]].x-xmid)-ret)>0)
            i++;
        int j=i+1,cnt=0;
        while (j<n && sign(a[ys[j]].y-a[ys[i]].y-ret)<=0)
        {
            if (sign(fabs(a[ys[j]].x-xmid)-ret)<=0)
            {
                ret=min(ret,dist(a[ys[i]],a[ys[j]]));
                if (++cnt>=10)
                    break;
            }
            j++;
        }
    }
    return(ret);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        a[i].in();
    sort(a,a+n);
    for (int i=0;i<n;i++)
        ys[i]=i;
    printf("%.10f\n",minimal(a,n,ys));
    return(0);
}

