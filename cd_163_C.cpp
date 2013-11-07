#include <cstdio>
#include <algorithm>
using namespace std;
double eps=1e-8;
struct event
{
    double x;
    int v;
    event(){}
    event(double x,int v):x(x),v(v){}
};
inline bool operator <(const event &a,const event &b)
{
    return(a.x<b.x);
}
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
event a[200010];
double ans[100010];
int main()
{
    int n,l,v1,v2;
    scanf("%d%d%d%d",&n,&l,&v1,&v2);
    double T=double(l)/(v1+v2),len=T*v2;
    int now=0;
    for (int i=1;i<=n;i++)
    {
        double x;
        scanf("%lf",&x);
        if (sign(x)>=0 && sign(x-len)==-1)
            now++;
        a[i]=event(x,-1);
        x-=len;
        if (sign(x)==-1)
            x+=2*l;
        a[i+n]=event(x,1);
    }
    sort(a+1,a+2*n+1);
    double last=0;
    for (int i=1;i<=2*n;i++)
    {
        double delta=a[i].x-last;
        ans[now]+=delta/(2*l);
        last=a[i].x;
        now+=a[i].v;
    }
    ans[now]+=(2*l-last)/(2*l);
    for (int i=0;i<=n;i++)
        printf("%.20f\n",ans[i]);
    return(0);
}

