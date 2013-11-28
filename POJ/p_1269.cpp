#include <cstdio>
#include <complex>
using namespace std;
typedef complex <double> point;
typedef const point &Point;
const double eps=1e-8;
void in(point &a)
{
    double x,y;
    scanf("%lf%lf",&x,&y);
    a=point(x,y);
}
int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
double det(Point a,Point b)
{
    return((conj(a)*b).imag());
}
int intersect(Point u1,Point u2,Point v1,Point v2,point &p)
{
    if (sign(det(u1-u2,v1-v2))==0)
        return(sign(det(u1-u2,v1-u2))==0);
    double t=det(u1-v1,v1-v2)/det(u1-u2,v1-v2);
    p=u1+(u2-u1)*t;
    return(-1);
}
int main()
{
    printf("INTERSECTING LINES OUTPUT\n");
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point u1,u2,v1,v2,p;
        in(u1),in(u2),in(v1),in(v2);
        int t=intersect(u1,u2,v1,v2,p);
        if (t==0)
            printf("NONE\n");
        else if (t==1)
            printf("LINE\n");
        else
            printf("POINT %.2f %.2f\n",p.real(),p.imag());
    }
    printf("END OF OUTPUT\n");
    return(0);
}

