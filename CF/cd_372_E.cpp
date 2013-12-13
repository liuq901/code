#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        x=double(a)/b,y=double(c)/d;
    }
    double len2() const
    {
        return(x*x+y*y);
    }
    double angle() const
    {
        return(atan2(y,x));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || sign(a.x-b.x)==0 && sign(a.y-b.y)<0);
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0);
}
inline point mid(const point &a,const point &b)
{
    return((a+b)/2);
}
inline point inverse(const point &p)
{
    return(p/p.len2());
}
struct state
{
    point p;
    double angle;
    state(const point &p,double angle):p(p),angle(angle){}
};
inline bool operator <(const state &a,const state &b)
{
    return(a.p<b.p || a.p==b.p && sign(a.angle-b.angle)<0);
}
map <state,int> M;
point p[1010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        p[i].in();
        p[i]=inverse(p[i]);
    }
    sort(p+1,p+n+1);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            M[state(mid(p[i],p[j]),(p[j]-p[i]).angle())]++;
    int ans=0;
    for (map <state,int>::iterator i=M.begin(),j;i!=M.end();i=j)
    {
        int sum=1,cnt=0;
        for (j=i;j!=M.end() && i->first.p==j->first.p;j++)
        {
            sum=ll(sum)*(j->second+1)%mod;
            cnt=(cnt+j->second)%mod;
        }
        ans=(ans+sum-cnt-1)%mod;
    }
    printf("%d\n",(ans+mod)%mod);
    return(0);
}

