#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-8;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(b.y-a.y)>0 || sign(b.y-a.y)==0 && sign(b.x-a.x)>0);
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double length(const point &a)
{
    return(sqrt(sqr(a.x)+sqr(a.y)));
}
inline bool cmp(const point &a,const point &b)
{
    int tmp=sign(det(a,b));
    if (tmp!=0)
        return(tmp>0);
    return(sign(length(b)-length(a))>0);
}
int n,seq[110];
double ans,opt[110][110];
point dot[110],list[110];
void solve(int vv)
{
    int len=0;
    for (int i=0;i<n;i++)
        if (dot[vv]<dot[i])
            list[len++]=dot[i]-dot[vv];
    for (int i=0;i<len;i++)
        for (int j=0;j<len;j++)
            opt[i][j]=0;
    sort(list,list+len,cmp);
    double v;
    for (int t=1;t<len;t++)
    {
        int _len=0,i;
        for (i=t-1;i>=0 && sign(det(list[t],list[i]))==0;i--);
        while (i>=0)
        {
            v=det(list[i],list[t])/2;
            seq[_len++]=i;
            int j;
            for (j=i-1;j>=0 && sign(det(list[i]-list[t],list[j]-list[t]))>0;j--);
            if (j>=0)
                v+=opt[i][j];
            ans=max(ans,v);
            opt[t][i]=v;
            i=j;
        }
        for (int i=_len-2;i>=0;i--)
            opt[t][seq[i]]=max(opt[t][seq[i]],opt[t][seq[i+1]]);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%lf%lf",&dot[i].x,&dot[i].y);
        ans=0;
        for (int i=0;i<n;i++)
            solve(i);
        printf("%.1f\n",ans);
    }
    return(0);
}

