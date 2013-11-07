#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
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
inline int sign(int x)
{
    return(x<0?-1:x>0);
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int side(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,b-a)));
}
inline bool intersect(const point &a,const point &b,const point &c,const point &d)
{
    return(side(c,a,b)!=side(d,a,b) && side(a,c,d)!=side(b,c,d));
}
inline int sqr(int x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(double(sqr(a.x-b.x)+sqr(a.y-b.y))));
}
int main()
{
    while (1)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1==0 && y1==0 && x2==0 && y2==0)
            break;
        point a(x1,y1),b(x2,y2),c,d;
        scanf("%d%d%d%d",&c.x,&c.y,&d.x,&d.y);
        double ans;
        if (intersect(a,b,c,d))
            ans=min(dist(a,c)+dist(b,c),dist(a,d)+dist(b,d));
        else
            ans=dist(a,b);
        static int id=0;
        printf("Case %d: %.3f\n",++id,ans/2);
    }
    return(0);
}

