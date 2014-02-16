#include <cstdio>
typedef long long ll;
struct point
{
    int x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    void in()
    {
        scanf("%d%d%d",&x,&y,&z);
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
inline ll dot(const point &a,const point &b)
{
    return(ll(a.x)*b.x+ll(a.y)*b.y+ll(a.z)*b.z);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline point pvec(const point &a,const point &b,const point &c)
{
    return(det(b-a,c-a));
}
inline bool oppo(const point &p,const point &q,const point &a,const point &b,const point &c)
{
    return(dot(p-a,pvec(a,b,c))*dot(q-a,pvec(a,b,c))<=0);
}
inline bool intersect(const point &p,const point &q,const point &a,const point &b,const point &c)
{
    return(oppo(p,q,a,b,c) && oppo(a,b,p,q,c) && oppo(a,c,p,q,b) && oppo(b,c,p,q,a));
}
int main()
{
    point p,q,a,b,c;
    p.in(),q.in(),a.in(),b.in(),c.in();
    printf("%s\n",intersect(p,q,a,b,c)?"MISS":"HIT");
    return(0);
}

