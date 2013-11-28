#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=100010;
const double zero=1e-8;
struct dot
{
    double x,y;
    dot(){}
    dot(double x,double y):x(x),y(y){}
    double dis()
    {
        return(sqrt(x*x+y*y));
    }
};
inline dot operator -(const dot &a,const dot &b)
{
    return(dot(a.x-b.x,a.y-b.y));
}
dot a[maxn];
int n,ys[maxn],tmp[maxn];
double ans;
void init()
{
    for (int i=0;i<n;i++)
        scanf("%lf%lf",&a[i].x,&a[i].y);
}
inline int dcmp(const double &v)
{
    if (v<-zero)
        return(-1);
    return(v>zero);
}
inline int xcmp(const dot &a,const dot &b)
{
    return(dcmp(a.x-b.x)<0);
}
inline bool ystmp(int v1,int v2)
{
    return(a[v1].y<a[v2].y);
}
double minimal_dis(dot *c,int n,int *ys)
{
    int mid=n/2;
    double ret=1e20,xmid=c[mid].x;
    if (n<20)
    {
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
            {
                if (dcmp((c[i]-c[j]).dis()-ret)<0)
                    ret=(c[i]-c[j]).dis();
                if (a[ys[i]].y>a[ys[j]].y)
                    swap(ys[i],ys[j]);
            }
        return(ret);
    }
    ret=min(minimal_dis(c,mid,ys),minimal_dis(c+mid,n-mid,ys+mid));
    merge(ys,ys+mid,ys+mid,ys+n,tmp,ystmp);
    copy(tmp,tmp+n,ys);
    for (int i=0;i<n;i++)
    {
        while (i<n && dcmp(fabs(a[ys[i]].x-xmid)-ret)>0)
            i++;
        int j=i+1,cnt=0;
        while (j<n && dcmp(a[ys[j]].y-a[ys[i]].y-ret)<=0)
        {
            if (dcmp(fabs(a[ys[j]].x-xmid)-ret)<=0)
            {
                ret=min(ret,(a[ys[i]]-a[ys[j]]).dis());
                if (++cnt>=10)
                    break;
            }
            j++;
        }
    }
    return(ret);
}
void work()
{
    sort(a,a+n,xcmp);
    for (int i=0;i<n;i++)
        ys[i]=i;
    ans=minimal_dis(a,n,ys);
}
void print()
{
    printf("%.3f\n",ans);
}
int main()
{
    scanf("%d",&n);
    init();
    work();
    print();
    return(0);
}

