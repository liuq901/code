#include <cstdio>
#include <cmath>
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    void in()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    double len2() const
    {
        return(x*x+y*y+z*z);
    }
    double len() const
    {
        return(sqrt(len2()));
    }
    point unit() const
    {
        double t=len();
        return(point(x/t,y/t,z/t));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y,a.z+b.z));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b,a.z*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b,a.z/b));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline double mix(const point &a,const point &b,const point &c)
{
    return(dot(det(a,b),c));
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    point dir=det(b-a,d-c);
    double s1=mix(b-a,c-a,dir),s2=mix(b-a,d-a,dir);
    return((c*s2-d*s1)/(s2-s1));
}
point a,b,c,d;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        a.in(),b.in(),c.in(),d.in();
        point n=det(b-a,d-c).unit();
        double len=dot(a-c,n);
        point P=intersect(a,b,c,d);
        point Q=P+n*len;
        printf("%f\n%f %f %f %f %f %f\n",fabs(len),Q.x,Q.y,Q.z,P.x,P.y,P.z);
    }
    return(0);
}

