#include <cstdio>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    void out() const
    {
        printf("%.10f %.10f\n",x,y);
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,b-a),s2=det(d-a,b-a);
    return((c*s2-d*s1)/(s2-s1));
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        point a,b,c,d;
        a.in(),b.in(),c.in(),d.in();
        intersect(a,b,c,d).out();
    }
    return(0);
}

