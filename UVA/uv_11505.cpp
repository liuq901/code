#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    double len()
    {
        return(sqrt(x*x+y*y));
    }
    point rotate(double t)
    {
        return(point(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t)));
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
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point p(0,0),dir(1,0);
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            char op[10];
            double x;
            scanf("%s%lf",op,&x);
            if (op[0]=='f')
                p=p+dir*x;
            else if (op[0]=='b')
                p=p-dir*x;
            else
            {
                x=x/180*pi;
                if (op[0]=='l')
                    dir=dir.rotate(-x);
                else
                    dir=dir.rotate(x);
            }
        }
        printf("%.0f\n",p.len());
    }
    return(0);
}

