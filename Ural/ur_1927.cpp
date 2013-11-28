#include <cstdio>
#include <cmath>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    point rotate()
    {
        return(point(-y,x));
    }
};
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0);
}
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline point get(const point &P,const point &A,const point &B)
{
    double rate=dot(P-A,B-A)/dot(B-A,B-A);
    return(A+(B-A)*rate);
}
inline bool online(const point &P,const point &A,const point &B)
{
    point p=get(P,A,B);
    return(sign(dot(p-A,p-B))<0);
}
inline int calc(const point &A,const point &B,const point &C,const point &D)
{
    if (online(A,C,D) || online(B,C,D) || online(C,A,B) || online(D,A,B))
        return(-1);
    if (get(A,C,D)==C && get(B,C,D)==D || get(A,C,D)==D && get(B,C,D)==C)
        return(-1);
    return(0);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,d-a);
    double s2=det(d-b,c-b);
    return((b-a)*(s1/(s1+s2))+a);
}
inline double area(point *a)
{
    double ret=0;
    for (int i=1;i<=4;i++)
        ret+=det(a[i-1],a[i]);
    return(fabs(ret)/2);
}
int main()
{
    point A,B,C,D;
    A.in(),B.in(),C.in(),D.in();
    if (sign(det(A-B,C-D))==0)
        printf("%d\n",calc(A,B,C,D));
    else
    {
        point d1=(A-B).rotate(),d2=(C-D).rotate(),p[5];
        p[1]=intersect(A+d1,A-d1,C+d2,C-d2);
        p[2]=intersect(B+d1,B-d1,C+d2,C-d2);
        p[3]=intersect(B+d1,B-d1,D+d2,D-d2);
        p[4]=intersect(A+d1,A-d1,D+d2,D-d2);
        p[0]=p[4];
        printf("%.10f\n",area(p));
    }
    return(0);
}

